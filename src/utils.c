#include "../include/utils.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

int readline(char* line, size_t size) {
    if (size == 0 || !line) {
        return 0;
    }

    if (fgets(line, size, stdin)) {
        line[strcspn(line, "\n")] = '\0';
        return 1;
    }
    return 0;
}

// Returns execution time in seconds
double sort_runtime(sort_fn sort, int* arr, int size) {
    clock_t time_start = clock();
    sort(arr, size);
    clock_t time_end = clock();

    double time_elapsed = (double) (time_end - time_start) / CLOCKS_PER_SEC;
    return time_elapsed;
}
