/*
    This file implements the sorting algorithm: selection sort
    Time Complexity: O(n^2)
    Space Complexity: O(1) (in-place)
*/
#include <stdio.h>

/// @brief Sorts the array in ascending order using Selection Sort.
/// @param arr Array to sort.
/// @param size Number of elements in the array.
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        // Find index of smallest element from i..end
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap if needed
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main(void) {
    int arr[64] = {
        600, 672, 421, 611, 907, 172, 931, 539, 950, 270, 800,
        78, 743, 501, 997, 377, 177, 700, 709, 269, 109, 169,
        136, 862, 528, 702, 69, 641, 367, 540, 458, 942, 538,
        605, 969, 175, 236, 930, 859, 602, 276, 960, 359, 935,
        816, 558, 2, 318, 996, 952, 397, 833, 46, 138, 937,
        785, 922, 186, 272, 369, 55, 855, 801, 445};
    int size = sizeof(arr) / sizeof(int);

    selectionSort(arr, size);  // Sorts in-place

    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }

    return 0;
}
