#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Lomuto partition: pivot at the end
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recurse on each side of the pivot
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(void) {
    int arr[64] = {600, 672, 421, 611, 907, 172, 931, 539, 950, 270, 800, 78,
                   743, 501, 997, 377, 177, 700, 709, 269, 109, 169, 136, 862,
                   528, 702, 69, 641, 367, 540, 458, 942, 538, 605, 969, 175,
                   236, 930, 859, 602, 276, 960, 359, 935, 816, 558, 2, 318,
                   996, 952, 397, 833, 46, 138, 937, 785, 922, 186, 272, 369,
                   55, 855, 801, 445};

    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d\n", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    return 0;
}
