#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList
{
    ListNode head;
    int length;
} LinkList;

ListNode *init_listnode(int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkList *init_linklist()
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->head.next = NULL;
    list->length = 0;
    return list;
}

void clear_listnode(ListNode *node)
{
    if (node == NULL)
        return;
    free(node);
    return;
}

void clear_linklist(LinkList *list)
{
    if (list == NULL)
        return;
    ListNode *p = list->head.next, *q;
    while (p)
    {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(list);
    return;
}

int insert(LinkList *list, int pos, int val)
{
    if (list == NULL)
        return 0;
    if (pos < 0 || pos > list->length)
        return 0;

    ListNode *p = &(list->head), *node = init_listnode(val);
    while (pos--)
    {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    list->length += 1;
    return 1;
}

int erase(LinkList *list, int pos)
{
    if (list == NULL)
        return 0;
    if (pos < 0 || pos >= list->length)
        return 0;
    ListNode *p = &(list->head), *q;
    while (pos--)
    {
        p = p->next;
    }
    q = p->next->next;
    clear_listnode(p->next);
    p->next = q;
    list->length -= 1;
    return 1;
}

void output(LinkList *list)
{
    if (list == NULL)
        return;
    printf("LinkList(%d) = ", list->length);
    for (ListNode *p = list->head.next; p; p = p->next)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main()
{
    srand(time(0));

    LinkList *list = init_linklist();
    for (int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 4;
        int pos = rand() % (list->length + 1);
        int val = rand() % 100;
        switch (op)
        {
        case 0:
        case 1:
        case 2:
            printf("Insert %d at %d into LinkList = %d\n", val, pos, insert(list, pos, val));
            break;
        case 3:
            printf("Erase at %d from LinkList = %d\n", pos, erase(list, pos));
            break;
        default:
            break;
        }
        output(list);
        printf("\n");
    }
    clear_linklist(list);
}