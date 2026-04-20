/*
    This implements the sorting algorithm: merge sort
    Time Complexity: O(n•logn)
    Space Complexity: O(n + logn) -> O(n)
*/
#include <stdlib.h>

int* merge(int low, int* lower, int high, int* upper) {
    int* merged_array = (int*) malloc((low + high) * sizeof(int));
    int i = 0, j = 0, count = 0;

    while (i < low && j < high) {
        if (lower[i] <= upper[j]) {
            merged_array[count++] = lower[i++];
        } else {
            merged_array[count++] = upper[j++];
        }
    }

    while (i < low) {
        merged_array[count++] = lower[i++];
    }
    while (j < high) {
        merged_array[count++] = upper[j++];
    }

    free(lower);
    free(upper);
    return merged_array;
}

int* msort(int low, int high, int* arr) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        int* lower_partition = msort(low, mid, arr);
        int* upper_partition = msort(mid + 1, high, arr);
        int* merged_array = merge((mid - low) + 1, lower_partition, (high - mid), upper_partition);
        return merged_array;
    } else {
        int* base = (int*) malloc(sizeof(int));
        base[0] = arr[low];
        return base;
    }

    return NULL;
}