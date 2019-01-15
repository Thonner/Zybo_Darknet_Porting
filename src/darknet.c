/*
 * darknet.c
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */
#include "darknet.h"
#include "xparameters.h"

#include "ov5640/OV5640.h"
#include "ov5640/AXI_VDMA.h"
#include "ov5640/PS_IIC.h"
#include "xtime_l.h"

void tes(){
	xil_printf("it works");
}


clock_t clock(){
	XTime time;
	XTime_GetTime(&time);

	return time;
}
