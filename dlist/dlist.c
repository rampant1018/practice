#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct _DList {
    DListNode *first;
    DListNode *last;
};

struct _DListNode {
    struct _DListNode *prev;
    struct _DListNode *next;
    void *data;
};

DList *dlist_create(void *data)
{
    DList *list;
    DListNode *node;

    list = (DList *)malloc(sizeof(DList));
    node = (DListNode *)malloc(sizeof(DListNode));

    node->next = node->prev = NULL;
    node->data = data;

    list->first = list->last = node;

    return list;
}

void dlist_append(DList *list, DListNode *thiz, void *data)
{
    DListNode *node;

    node = (DListNode *)malloc(sizeof(DListNode));

    node->data = data;
    node->next = thiz->next;
    node->prev = thiz;

    if(thiz == list->last) {
        list->last = node;
    }
    else {
        thiz->next->prev = node;
    }
    thiz->next = node;
}

DListNode *dlist_find(DList *list, void *data, DListDataCompare cmp)
{
    DListNode *node;

    for(node = list->first; node != NULL; node = node->next) {
        if(!cmp(data, node->data)) {
            return node;
        }
    }

    return list->last;
}

void dlist_display(DList *list, DListDataPrint printer)
{
    DListNode *node;

    for(node = list->first; node != NULL; node = node->next) {
        printer(node->data);
        printf(" ");
    }
    printf("\n");

    for(node = list->last; node != NULL; node = node->prev) {
        printer(node->data);
        printf(" ");
    }
    printf("\n");
}

void dlist_destory(DList *list)
{
    DListNode *node, *node_tmp;

    for(node = list->first->next; node != NULL; node = node->next) {
        free(node->prev);
    }
    free(list->last);
}
