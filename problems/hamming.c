#include <stdio.h>
#include <string.h>

int compute(const char* lhs, const char* rhs) {
    int llen = strlen(lhs);
    int rlen = strlen(rhs);
    if (llen != rlen) {
        return -1;
    }

    int diff = 0;
    for (int i = 0; i < llen; i++) {
        if (lhs[i] != rhs[i]) {
            diff++;
        }
    }
    return diff;
}

int main(void) {
    const char* lhs =
        "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC"
        "GTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGT"
        "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC"
        "GTACGTACGTACGT";
    const char* rhs =
        "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC"
        "GTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGT"
        "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC"
        "GTACGTACGTACGA";

    int hamming_dist = compute(lhs, rhs);
    printf("The Hamming distance is %d.\n", hamming_dist);
    return 0;
}