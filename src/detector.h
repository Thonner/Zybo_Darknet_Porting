/*
 * detector.h
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */

#ifndef SRC_DETECTOR_H_
#define SRC_DETECTOR_H_

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
#include "xparameters.h"
using namespace digilent;

void test_detector(char *picture_base_addr, int pic_width, int pic_hieght, AXI_VDMA<ScuGicInterruptController>& vdma_driver);

#endif /* SRC_DETECTOR_H_ */
