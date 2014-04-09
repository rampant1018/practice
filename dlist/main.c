#include "dlist.h"

int main()
{
    DListNode *node;

    dlist_create(5);

    node = dlist_find(1);
    dlist_append(node, 3);
    dlist_append(node, 4);
    node = dlist_find(4);
    dlist_append(node, 2);
    dlist_append(node, 1);
    dlist_display();

    dlist_destory();

    return 0;
}
