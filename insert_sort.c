#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 10

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(&num[j], &num[j - 1]);
        }
    }
    return;
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
    insert_sort(num, MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", num[i]);
    }

}
