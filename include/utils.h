#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef int* (*sort_fn)(int*, int);

// Reads line from stdin according to size
int readline(char* line, size_t size);
// Returns runtime of the sorting function in secs.
double sort_runtime(sort_fn, int*, int);