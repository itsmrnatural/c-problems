/*
    This implements the sorting algorithm: selection sort
    Time Complexity: O(n^2)
    Space Complexity: Non-ideal
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void removeElement(int* arr, int* size, int index) {
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int findSmallest(int* arr, int size) {
    int sm = arr[0];
    int si = 0;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < sm) {
            sm = arr[i];
            si = i;
        }
    }
    return si;
}

int* selectionSort(int* arr, int size) {
    int* sortedArray = (int*) malloc(size);

    int msize = size;
    for (int i = 0; i < size - 1; i++) {
        int si = findSmallest(arr, msize);
        sortedArray[i] = arr[si];
        removeElement(arr, &msize, si);  // Deletes the smallest element from the original array.
    }
    return sortedArray;
}
