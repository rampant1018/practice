#include <stdint.h>
#include "dlist.h"

static int dlist_node_cmp(void *val1, void *val2)
{
    return (int)val1 - (int)val2;
}

static void dlist_node_print(void *data, void *ctx)
{
    printf("%d ", (int)data);
}

int main()
{
    DList *list;
    DListNode *node;
    void *ctx;

    list = dlist_create((void *) 15);
    node = dlist_find(list, (void *)10, dlist_node_cmp);
    dlist_append(list, node, (void *)5);
    dlist_append(list, node, (void *)3);
    dlist_append(list, node, (void *)1);
    dlist_append(list, node, (void *)2);
    dlist_append(list, node, (void *)4);
    dlist_foreach(list, dlist_node_print, ctx);

    dlist_destory(list);

    return 0;
}
