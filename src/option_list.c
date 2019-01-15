/*
 * option_list.c
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "option_list.h"
#include "darknet.h"
#include "list.h"

void option_insert(list *l, char *key, char *val)
{
    kvp *p = (kvp*)ta_alloc(sizeof(kvp));
    p->key = key;
    p->val = val;
    p->used = 0;
    list_insert(l, p);
}
list *read_data_cfg(){
	list *options = make_list();

	option_insert(options, "classes", "80");
	option_insert(options, "train", "/home/pjreddie/data/coco/trainvalno5k.txt");
	option_insert(options, "valid", "coco_testdev");
	option_insert(options, "names", "data/coco.names");
	option_insert(options, "backup", "/home/pjreddie/backup/");

	return options;
}

int option_find_int(list *l, char *key, int def)
{
    char *v = option_find(l, key);
    if(v) return atoi(v);
    fprintf(stderr, "%s: Using default '%d'\n", key, def);
    return def;
}


char *option_find(list *l, char *key)
{
    node *n = l->front;
    while(n){
        kvp *p = (kvp *)n->val;
        if(strcmp(p->key, key) == 0){
            p->used = 1;
            return p->val;
        }
        n = n->next;
    }
    return 0;
}

float option_find_float(list *l, char *key, float def)
{
    char *v = option_find(l, key);
    if(v) return atof(v);
    fprintf(stderr, "%s: Using default '%lf'\n", key, def);
    return def;
}

int option_find_int_quiet(list *l, char *key, int def)
{
    char *v = option_find(l, key);
    if(v) return atoi(v);
    return def;
}

float option_find_float_quiet(list *l, char *key, float def)
{
    char *v = option_find(l, key);
    if(v) return atof(v);
    return def;
}
void option_unused(list *l)
{
    node *n = l->front;
    while(n){
        kvp *p = (kvp *)n->val;
        if(!p->used){
            fprintf(stderr, "Unused field: '%s = %s'\n", p->key, p->val);
        }
        n = n->next;
    }
}

char *option_find_str(list *l, char *key, char *def)
{
    char *v = option_find(l, key);
    if(v) return v;
    if(def) fprintf(stderr, "%s: Using default '%s'\n", key, def);
    return def;
}

