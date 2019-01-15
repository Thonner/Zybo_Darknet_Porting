/*
 * list.h
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */

#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include "darknet.h"

list *make_list();

void list_insert(list *l, void *val);

#endif /* SRC_LIST_H_ */
