#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

typedef struct Stack
{
    int *data;
    int head, length;
} Stack;

Stack *init(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->head = -1;
    s->length = n;
    return s;
}

int empty(Stack *s)
{
    return s->head == -1;
}

int top(Stack *s)
{
    return s->data[s->head];
}

int push(Stack *s, int val)
{
    if (s == NULL)
        return 0;
    if (s->head == s->length - 1)
        return 0;
    s->head += 1;
    s->data[s->head] = val;
    return 1;
}

int pop(Stack *s)
{
    if (s == NULL)
        return 0;
    if (empty(s))
        return 0;
    s->head--;
    return 1;
}

void clear(Stack *s)
{
    if (s == NULL)
        return;
    free(s->data);
    free(s);
    return;
}

void output(Stack *s)
{
    printf("Stack = [");
    for (int i = s->head; i >= 0; i--)
    {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
}

int main()
{
    srand(time(0));
    Stack *s = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 2, val = rand() % 100;
        switch (op)
        {
        case 0:
            printf("Push %d into Stack = %d\n", val, push(s, val));
            break;
        case 1:
            printf("Pop %d from Stack = %d\n", top(s), pop(s));
            break;
        default:
            break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}