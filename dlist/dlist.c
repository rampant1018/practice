#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct _DListNode {
    struct _DListNode *prev;
    struct _DListNode *next;
    int value;
};

DListNode *first = NULL, *last = NULL;

void dlist_create(int value)
{
    DListNode *node;

    node = (DListNode *)malloc(sizeof(DListNode));

    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    first = last = node;
}

void dlist_append(DListNode *thiz, int value)
{
    DListNode *node;

    node = (DListNode *)malloc(sizeof(DListNode));

    node->value = value;
    node->next = thiz->next;
    node->prev = thiz;

    if(thiz == last) {
        last = node;
    }
    else {
        thiz->next->prev = node;
    }
    thiz->next = node;
}

DListNode *dlist_find(int value)
{
    DListNode *node;

    for(node = first; node != NULL; node = node->next) {
        if(node->value == value) {
            return node;
        }
    }

    return last;
}

void dlist_display()
{
    DListNode *node;

    for(node = first; node != NULL; node = node->next) {
        printf("%d ", node->value);
    }
    printf("\n");

    for(node = last; node != NULL; node = node->prev) {
        printf("%d ", node->value);
    }
    printf("\n");
}

void dlist_destory()
{
    DListNode *node, *node_tmp;

    for(node = first->next; node != NULL; node = node->next) {
        free(node->prev);
    }
    free(last);
}
