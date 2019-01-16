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
        free_detections(dets, nboxes);

	}
}
