/*
 * parser.h
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include "darknet.h"

LAYER_TYPE string_to_layer_type(char * type);


typedef struct{
    char *type;
    list *options;
}section;

network *parse_network_cfg();
list *read_cfg();
void parse_net_options(list *options, network *net);

learning_rate_policy get_policy(char *s);
void free_section(section *s);


#endif /* SRC_PARSER_H_ */
