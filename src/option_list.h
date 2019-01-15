/*
 * option_list.h
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */
#include "darknet.h"
#ifndef SRC_OPTION_LIST_H_
#define SRC_OPTION_LIST_H_

typedef struct{
    char *key;
    char *val;
    int used;
} kvp;

void option_insert(list *l, char *key, char *val);

int option_find_int(list *l, char *key, int def);

char *option_find(list *l, char *key);

float option_find_float(list *l, char *key, float def);

list * read_data_cfg();


int option_find_int_quiet(list *l, char *key, int def);

float option_find_float_quiet(list *l, char *key, float def);
char *option_find_str(list *l, char *key, char *def);
void option_unused(list *l);


#endif /* SRC_OPTION_LIST_H_ */
