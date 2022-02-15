#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

typedef struct Vector
{
    int *data;
    int size, length;
} Vector;

Vector *init(int n)
{
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;

    return vec;
}

int expand(Vector *vec)
{
    if (vec == NULL)
        return 0;
    int new_size = vec->size * 2;
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size);
    if (p == NULL)
        return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

int insert(Vector *vec, int pos, int val)
{
    if (vec == NULL)
        return 0;
    if (pos < 0 || pos > vec->length)
        return 0;
    if (vec->length == vec->size)
    {
        if (!expand(vec))
            return 0;
        printf("Expand vector size to %d success\n", vec->size);
    }
    for (int i = vec->length; i > pos; i--)
    {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[pos] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int pos)
{
    if (vec == NULL)
        return 0;
    if (pos < 0 || pos >= vec->length)
        return 0;
    for (int i = pos; i < vec->length - 1; i++)
    {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec)
{
    printf("Array(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Vector *vec)
{
    if (vec == NULL)
    {
        return;
    }
    free(vec->data);
    free(vec);
    return;
}

int main()
{
    srand(time(0));
    Vector *vec = init(1);
    int op, pos, val;
    for (int i = 0; i < MAX_OP; i++)
    {
        op = rand() % 4;
        pos = rand() % (vec->length + 1);
        val = rand() % 100;
        switch (op)
        {
        case 0:
        case 1:
        case 2:
            printf("Insert %d at %d to vector = %d\n", val, pos, insert(vec, pos, val));
            break;
        case 3:
            printf("Erase item at %d from vector = %d\n", pos, erase(vec, pos));
            break;
        default:
            break;
        }
        output(vec);
    }
    return 0;
}
