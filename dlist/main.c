#include <stdint.h>
#include <stdlib.h>
#include "dlist.h"

static int dlist_node_cmp(void *val1, void *val2)
{
    return (int)val1 - (int)val2;
}

static void dlist_node_print(void *data, void *ctx)
{
    printf("%d ", (int)data);
}

static void dlist_find_max(void *data, void *ctx)
{
    int *max = ctx;

    if(*max < (int)data) {
        *max = (int)data;
    }
}

static void dlist_sum(void *data, void *ctx)
{
    int *sum = ctx;

    *sum += (int)data;
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

    int max = 0;
    dlist_foreach(list, dlist_find_max, &max);
    printf("\nmax: %d\n", max);

    int sum = 0;
    dlist_foreach(list, dlist_sum, &sum);
    printf("\nsum: %d\n", sum);

    dlist_destory(list);

    return 0;
}
