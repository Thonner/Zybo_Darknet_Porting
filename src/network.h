/*
 * network.h
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */

#ifndef SRC_NETWORK_H_
#define SRC_NETWORK_H_
#include "darknet.h"
network *load_network();
void calc_network_cost(network *net);


#endif /* SRC_NETWORK_H_ */
