/*
 * list.c
 *
 *  Created on: Jan 14, 2019
 *      Author: thonner
 */
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "darknet.h"

list * make_list()
{
	list *l = (list*)malloc(sizeof(list));
	l->size = 0;
	l->front = 0;
	l->back = 0;
	return l;
}

void list_insert(list *l, void *val)
{
	node *new2 = (node*)malloc(sizeof(node));
	new2->val = val;
	new2->next = 0;

	if(!l->back){
		l->front = new2;
		new2->prev = 0;
	}else{
		l->back->next = new2;
		new2->prev = l->back;
	}
	l->back = new2;
	++l->size;
}

void free_node(node *n)
{
	node *next;
	while(n) {
		next = n->next;
		//free(n);
		n = next;
	}
}

void free_list(list *l)
{
	free_node(l->front);
	//free(l);
}


void **list_to_array(list *l)
{
    void **a = (void**)calloc(l->size, sizeof(void*));
    int count = 0;
    node *n = l->front;
    while(n){
        a[count++] = n->val;
        n = n->next;
    }
    return a;
}
