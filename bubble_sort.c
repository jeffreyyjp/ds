#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 10

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *num, int n) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                flag = 1;
                swap(&num[j], &num[j + 1]);
            }
        }
        if (flag == 0) break;    
    }
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
    bubble_sort(num, MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", num[i]);
    }
}
