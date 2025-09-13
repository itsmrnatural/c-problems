/*
    This file implements the sorting algorithm: selection sort
    Time Complexity: O(n_sq)
*/
#include <ctype.h>
#include <stdio.h>

void delElm(int *arr, int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int findSmallest(int *arr, int size) {
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

void selectionSort(int *arr, int size, int *newarr) {
    int msize = size;
    for (int i = 0; i < size - 1; i++) {
        int si = findSmallest(arr, msize);
        newarr[i] = arr[si];
        delElm(arr, &msize, si); // Deletes the smallest element from the original array.
    }
}

int main(void) {
    int arr[64] = {600, 672, 421, 611, 907, 172, 931, 539, 950, 270, 800, 78,
                   743, 501, 997, 377, 177, 700, 709, 269, 109, 169, 136, 862,
                   528, 702, 69, 641, 367, 540, 458, 942, 538, 605, 969, 175,
                   236, 930, 859, 602, 276, 960, 359, 935, 816, 558, 2, 318,
                   996, 952, 397, 833, 46, 138, 937, 785, 922, 186, 272, 369,
                   55, 855, 801, 445};
    int size = sizeof(arr) / sizeof(int);
    int newarr[size];
    selectionSort(arr, size, newarr); // Fills the newarr variable with the sorted version of arr.

    for (int i = 0; i < size - 1; i++) {
        if (i == size - 1) {
            printf("%d\n", newarr[i]);
            break;
        }
        printf("%d, ", newarr[i]);
    }

    return 0;
}
