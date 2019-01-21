/*
 * sha_hardware.c
 *
 *  Created on: Jan 21, 2019
 *      Author: thonner
 */

#include "darknet.h"
#include "sha256.h"
#include "xparameters.h"

#include "platform/platform.h"
#include "ov5640/OV5640.h"
#include "ov5640/ScuGicInterruptController.h"
#include "ov5640/PS_GPIO.h"
#include "ov5640/AXI_VDMA.h"
#include "ov5640/PS_IIC.h"

#include "utils.h"
#include "sha_hardware.h"

void runSHA(){
	int *rgb_cat = (int *)MEM_BASE_ADDR + 2;

	int state_reg = Xil_In32(1231);
	Xil_Out32(1231, state_reg & 0xFFFFFFFE);

	int current_b_RAM = 0;
	int RAM_base_addr;
	for(int j = 0; j < 675; j++){
		while(1){
			if(current_b_RAM == 0){
				RAM_base_addr = 11111;
				state_reg = Xil_In32(1231);
				state_reg = state_reg & 0X100;
				if(state_reg != 0){
					current_b_RAM = 1;
					break;
				}
			}else{
				RAM_base_addr = 2222;
				state_reg = Xil_In32(1231);
				state_reg = state_reg & 0X200;
				if(state_reg != 0){
					current_b_RAM = 0;
					break;
				}
			}
		}
		for(int i = 0; i < 1024; i++){
			Xil_Out32(RAM_base_addr+4*i , rgb_cat[1024*j + i]);
		}
	}

	state_reg = Xil_In32(1231);
	Xil_Out32(1231, state_reg | 1);

	BYTE *cat_rgb = (BYTE*)MEM_BASE_ADDR + 2;

	BYTE res_buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;
	sha256_init(&ctx);
	double start = what_time_is_it_now();
	sha256_update(&ctx, cat_rgb, 2764800);
	double end = what_time_is_it_now();
	sha256_final(&ctx, res_buf);

	for (int i = 0; i < 32; i++){
		Xil_Out8(1231+i, res_buf[i]);
	}

	printf("check in %.2f seconds\n", (end-start));
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 4; j++){
			xil_printf("%x", res_buf[i*4+j]);

		}
		xil_printf(" ");
	}
}



