#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    int diff = 0;

    // Walk through both strings at the same time
    for (; *lhs && *rhs; lhs++, rhs++) {
        if (*lhs != *rhs)
            diff++;
    }

    // If one string ended but the other didn't, lengths differ
    return (*lhs || *rhs) ? -1 : diff;
}

int main(void) {
    const char *lhs = "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGT";
    const char *rhs = "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGA";

    int hamming_dist = compute(lhs, rhs);
    printf("The Hamming distance is %d.\n", hamming_dist);
    return 0;
}