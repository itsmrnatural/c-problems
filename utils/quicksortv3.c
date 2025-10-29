/*
    This implements the sorting algorithm: quick sort (Hoare partition)
    Time Complexity: O(n•logn) average, O(n^2) worst
    Space Complexity: O(logn) (due to recursion)
*/
#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (i < j) {
        // Find an element on the left side that should be on the right
        do {
            i++;
        } while (arr[i] < pivot);

        // Find an element on the right side that should be on the left
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
    return j;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recurse on each side of the pivot
        quicksort(arr, low, pi);
        quicksort(arr, pi + 1, high);
    }
}
