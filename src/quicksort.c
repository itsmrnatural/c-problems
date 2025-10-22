/*
    This implements the sorting algorithm: quick sort
    Time Complexity: Average: O(n•logn), Worst: O(n^2)
    Space Complexity: O(n) (not in-place)
*/
#include <stdio.h>
#include <stdlib.h>

// forward declarations
int* quicksort(int* arr, int size);
void partition(int pivot, int* arr, int size, int* lesser, int* greater, int* lesser_size, int* greater_size);
int* concat(int* left, int left_size, int pivot, int* right, int right_size);

void partition(
    int pivot, int* arr, int size,
    int* lesser, int* greater,
    int* lesser_size, int* greater_size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < pivot) {
            lesser[(*lesser_size)++] = arr[i];
        } else {
            greater[(*greater_size)++] = arr[i];
        }
    }
}

int* concat(int* left, int left_size, int pivot, int* right, int right_size) {
    int total = left_size + 1 + right_size;
    int* out = malloc(total * sizeof(int));

    int k = 0;
    for (int i = 0; i < left_size; i++)
        out[k++] = left[i];
    out[k++] = pivot;
    for (int i = 0; i < right_size; i++)
        out[k++] = right[i];

    return out;
}

int* quicksort(int* arr, int size) {
    if (size < 2) {
        int* base = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            base[i] = arr[i];
        return base;
    }

    int pivot = arr[0];
    int* lesser = malloc(size * sizeof(int));
    int* greater = malloc(size * sizeof(int));
    int lesser_size = 0, greater_size = 0;

    partition(pivot, arr, size, lesser, greater, &lesser_size, &greater_size);

    int* sorted_lesser = quicksort(lesser, lesser_size);
    int* sorted_greater = quicksort(greater, greater_size);

    free(lesser);
    free(greater);

    int* result = concat(sorted_lesser, lesser_size, pivot, sorted_greater, greater_size);

    free(sorted_lesser);
    free(sorted_greater);

    return result;
}