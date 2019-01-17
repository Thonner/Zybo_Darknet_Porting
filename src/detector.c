/*
 * detector.c
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */
#include "darknet.h"
#include "option_list.h"
#include "network.h"
#include "utils.h"
#include "box.h"
#include "platform/platform.h"
#include "ov5640/OV5640.h"
#include "ov5640/ScuGicInterruptController.h"
#include "ov5640/PS_GPIO.h"
#include "ov5640/AXI_VDMA.h"
#include "ov5640/PS_IIC.h"
#include "MIPI_D_PHY_RX.h"
#include "MIPI_CSI_2_RX.h"



void set_osd_reg(image im, detection *dets, int num, float thresh, char **names,/* image **alphabet,*/ int classes){
	int i,j;

	int res[num][3];
	int index = 0;

	for(i = 0; i < num; ++i){
		char labelstr[4096];
		memset(&labelstr,0,sizeof(labelstr));

		int temp = 42;


		int classs = -1;
		for(j = 0; j < classes; ++j){
			if (dets[i].prob[j] > thresh){
				if (classs < 0) {
					strcat(labelstr, names[j]);
					classs = j;
				} else {
					strcat(labelstr, ", ");
					strcat(labelstr, names[j]);
				}
				//printf("%s: %.0f%%\n", names[j], dets[i].prob[j]*100);
				res[index][0] = i;
				res[index][1] = j;
				res[index][2] = (int)(dets[i].prob[j]*100);

				index++;

			}
		}
	}
	int largest = 0;
	int temp[3];
	for(int i = 0; i < 3; i++){
		largest = res[i][2];
		for(int j = i ; j < num; j++){
			if(res[j][2] > largest){
				largest = res[j][2];
				for(int k = 0 ; k < 3; k++){
					temp[k] = res[i][k];
					res[i][k] = res[j][k];
					res[j][k] = temp[k];
				}
			}
		}
	}
	Xil_Out32(OSD_BASE_ADDR, (int)((dets[res[0][0]].bbox.x * im.w)));
	Xil_Out32(OSD_BASE_ADDR+4, (int)((dets[res[0][0]].bbox.y * im.h)));
	Xil_Out32(OSD_BASE_ADDR+8, (int)((dets[res[0][0]].bbox.w * im.w)));
	Xil_Out32(OSD_BASE_ADDR+12, (int)((dets[res[0][0]].bbox.h * im.h)));
	Xil_Out32(OSD_BASE_ADDR+16, 10);

	char write[6];
	write[0] = names[res[0][j]][0];
	write[1] = names[res[0][j]][1];
	write[2] = names[res[0][j]][2];
	write[3] = names[res[0][j]][3];
	write[4] = res[0][2]/10 + '0';
	write[5] = res[0][2]%10 + '0';

	int value = 0;
	for(int i = 0; i < 4; i++){
		int temp = write[i] - 'a';
		temp = temp << i*5;
		value = value | temp;
	}
	for(int i = 0; i < 2; i++){
		int temp = write[i] - '0' +22;
		temp = temp << (i+4)*5;
		value = value | temp;
	}

	Xil_Out32(OSD_BASE_ADDR+20, value);

}

void test_detector(){
	list *options = read_data_cfg();
	char *name_list = "data/coco.names";
	char * names[] = {"person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat", "traffic light", "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed", "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear", "hair drier", "toothbrush"};

	network *net = load_network();
	set_batch_network(net, 1);
	srand(2222222);
	double time;
	char buff[256];
	char *input = buff;
	float nms=.45;

	while(1){ // while for multiple photos
		char *image_base_addr = (char*)(0x3D609D00);
		image im = load_image_color(image_base_addr,0,0);
		image sized = letterbox_image(im, net->w, net->h);
		layer l = net->layers[net->n-1];

        float *X = sized.data;
        time=what_time_is_it_now();
        network_predict(net, X);
        printf("%s: Predicted in %f seconds.\n", input, what_time_is_it_now()-time);
        int nboxes = 0;
        detection *dets = get_network_boxes(net, im.w, im.h, 0.5, 0.5, 0, 1, &nboxes);
        if (nms) do_nms_sort(dets, nboxes, l.classes, nms);
        draw_detections(im, dets, nboxes, 0.5, names, l.classes);
        set_osd_reg(im, dets, nboxes, 0.5, names, l.classes);
        free_detections(dets, nboxes);

	}
}
