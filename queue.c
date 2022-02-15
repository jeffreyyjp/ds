#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

typedef struct Queue {
    int *data;
    int head, tail;
    int length, size;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = 0;
    q->length = n;
    q->size = 0;
    return q;
}

int empty(Queue *q) {
    return q->size == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->size == q->length) return 0;
    q->data[q->tail++] = val;
    if (q->tail == q->length) {
        q->tail -= q->length;
    }
    q->size++;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->length) {
        q->head -= q->length;
    }
    q->size--;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

void output(Queue *q) {
    printf("Queue = [");
    for (int i = 0; i < q->size; i++) {
        printf(" %d", q->data[(i + q->head) % q->length]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    Queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 3;
	int val = rand() % 100;
	int head = front(q);
	switch(op) {
	case 0:
	case 1:
	    printf("Push %d into Queue = %d\n", val, push(q, val));
	    break;
	case 2:
	    printf("Pop %d from Queue = %d\n", head, pop(q));
	    break;
	default:
	    break;
	}
	output(q);
	printf("\n");
    }

    printf("------------------------\n");

    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
	printf("Push %d into Queue = %d\n", val, push(q, val));
	output(q);
	printf("\n");
    }
    clear(q);
    return 0;
}
