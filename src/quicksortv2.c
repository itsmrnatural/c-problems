/*
    This implements the sorting algorithm: quick sort (Lomuto partition)
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
    int pivot = arr[high];  // Lomuto partition: pivot at the end
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // When all elements <= pivot are before index 'i' insert pivot
    // after i by swapping i+1 and pivot
    // Effectively divides array into [<=, pivot, >]
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recurse on each side of the pivot
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
