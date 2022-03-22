#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

#define MAX_OP 20


void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(n));
    q->cnt = 0, q->size =  n;
    return q;
}

int empty(priority_queue * q) {
    return q->cnt == 0;
}

int top(priority_queue * q) {
    return q->data[0];
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->data[q->cnt++] = val;
    int tmp = q->cnt - 1;
    while (tmp >> 1 >= 0 && q->data[tmp] > q->data[tmp >> 1]) {
        swap(&q->data[tmp], &q->data[tmp >> 1]);
        tmp = tmp >> 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[0] = q->data[q->cnt];
    q->cnt--;
    int tmp = 0;
    while (tmp < q->cnt) {
        int larger = tmp;
        int left = 2 * tmp + 1, right = 2 * tmp + 2;
        if (left < q->cnt && q->data[tmp] < q->data[left]) tmp = left;
        if (right < q->cnt && q->data[tmp] < q->data[right]) tmp = right;
        if (tmp == larger) break;
        swap(&q->data[tmp], &q->data[larger]);
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    srand(time(0));
    priority_queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("Push %d into queue\n", val);
    }
    while(!empty(q)) {
        printf("%d ", top(q));
        pop(q);
    }
    return 0;
}
