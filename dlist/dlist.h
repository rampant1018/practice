#ifndef _DLIST_H_
#define _DLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

struct _DList;
typedef struct _DList DList;

struct _DListNode;
typedef struct _DListNode DListNode;

typedef int (*DListDataCompare)(void *val1, void *val2);
typedef void (*DListVisitFunc)(void *data, void *ctx);

DList *dlist_create();
void dlist_append(DList *list, DListNode *thiz, void *data);
DListNode *dlist_find(DList *list, void *data, DListDataCompare cmp);
void dlist_foreach(DList *list, DListVisitFunc visit, void *ctx);
void dlist_destory(DList *list);

#ifdef __cplusplus
extern }
#endif
#endif
