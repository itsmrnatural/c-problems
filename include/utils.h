#pragma once
#include <stdio.h>
#include <string.h>

static int readline(char* line, size_t size) {
    if (size == 0 || !line) {
        return 0;
    }

    if (fgets(line, size, stdin)) {
        line[strcspn(line, "\n")] = '\0';
        return 1;
    }
    return 0;
}
