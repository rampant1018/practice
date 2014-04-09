#ifndef _DLIST_H_
#define _DLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

struct _DListNode;
typedef struct _DListNode DListNode;

void dlist_create(int value);
void dlist_append(DListNode *thiz, int value);
DListNode *dlist_find(int value);
void dlist_display();
void dlist_destory();

#ifdef __cplusplus
extern }
#endif
#endif
