/*
    This implements the sorting algorithm: selection sort
    Time Complexity: O(n^2)
    Space Complexity: O(1) (in-place)
*/

int* selectionSort(int* arr, int size) {
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
    return arr;
}
