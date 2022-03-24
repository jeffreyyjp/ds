#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OP 10

void merge_sort(int *num, int l, int r) {
    if (r <= l) return;
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *tmp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            tmp[k++] = num[p1++];
        } else {
            tmp[k++] = num[p2++];
        }
    }
    memcpy(num + l, tmp, sizeof(int) * (r - l + 1));
    free(tmp);
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
    merge_sort(num, 0, MAX_OP - 1);
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
