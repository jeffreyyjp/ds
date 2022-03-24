#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OP 10

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *num, int l, int r) {
    if (r <= l) return;
    int p1 = l + 1, p2 = r;
    while (1) {
        while (num[p1] < num[l]) {
            if (p1 == r) break;
            p1++;
        }
        while (num[p2] > num[l]) {
            if (p2 == l) break;
            p2--;
        }
        if (p1 >= p2) break;
        swap(&num[p1], &num[p2]);
    }
    swap(&num[l], &num[p2]);
    quick_sort(num, l, p2 - 1);
    quick_sort(num, p2 + 1, r);
}

int main() {
    srand(time(0));
    int *num = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        num[i] = val;
        printf("%d ", val);
    }
    printf("\n");
    quick_sort(num, 0, MAX_OP - 1);
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
