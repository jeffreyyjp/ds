#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heapify(int *arr, int root, int size) {
    int tmp = root;
    while (tmp < size) {
        int larger = tmp;
        int left = 2 * tmp + 1, right = 2 * tmp + 2;
        if (left < size && arr[tmp] < arr[left]) tmp = left;
        if (right < size && arr[tmp] < arr[right]) tmp = right;
        if (tmp == larger) break;
        swap(&arr[tmp], &arr[larger]);
    }
}

void heap_sort(int *arr, int n) {
    // build max heap
    for (int i = (n - 2) / 2; i >= 0; i--) {
        max_heapify(arr, i, n);
    }

    // sort the arr using heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main() {
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    heap_sort(arr, MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", arr[i]);
    }
}
