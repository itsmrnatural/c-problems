#include <stdio.h>
#include <stdlib.h>  // for malloc

// forward declarations
int* quicksort(int* arr, int size);
void partition(int pivot, int* arr, int size, int* lesser, int* greater, int* lesser_size, int* greater_size);
int* concat(int* left, int left_size, int pivot, int* right, int right_size);

int main(void) {
    int arr[64] = {
        600, 672, 421, 611, 907, 172, 931, 539, 950, 270, 800, 78,
        743, 501, 997, 377, 177, 700, 709, 269, 109, 169, 136, 862,
        528, 702, 69, 641, 367, 540, 458, 942, 538, 605, 969, 175,
        236, 930, 859, 602, 276, 960, 359, 935, 816, 558, 2, 318,
        996, 952, 397, 833, 46, 138, 937, 785, 922, 186, 272, 369,
        55, 855, 801, 445};

    int size = sizeof(arr) / sizeof(int);
    int* sorted_arr = quicksort(arr, size);

    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d\n", sorted_arr[i]);
        } else {
            printf("%d, ", sorted_arr[i]);
        }
    }

    free(sorted_arr);  // cleanup
    return 0;
}

// does recursion, delegates work
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

// does *only* splitting
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

// glues left + pivot + right
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
