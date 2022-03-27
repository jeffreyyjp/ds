#include <stdio.h>

int binary_search(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid  - 1;
        else head = mid + 1;
    }
    
    return -1;
}

int main() {
    int arr1[5] = {1, 3, 5, 7, 9};
    printf("Search 5 in arr1:\n");
    printf("Get it in %d", binary_search(arr1, 5, 5));
    return 0;
}
