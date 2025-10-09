#pragma once
#include <stdio.h>
#include <string.h>

inline void readline(char* line, size_t size) {
    if (fgets(line, size, stdin)) {
        line[strcspn(line, "\n")] = '\0';  // strip newline
    }
}
