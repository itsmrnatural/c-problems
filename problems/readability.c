#include "../include/utils.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define LINE_BUFFER_SIZE 256

int main(void) {
    char line[LINE_BUFFER_SIZE];
    printf("Line to be graded:\n");
    readline(line, sizeof(line));

    int letters = 0, words = 0, sentences = 0;
    int in_word = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (isalpha(line[i])) {
            letters++;
            in_word = 1;
        } else if (isspace(line[i])) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else if (line[i] == '.' || line[i] == '!' || line[i] == '?') {
            sentences++;
            if (in_word) {
                words++;
                in_word = 0;
            }
        }
    }
    if (in_word) words++;  // last word

    if (words == 0) {
        printf("Error: No words found in the input.\n");
        return 1;
    }

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;

    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int rgrade = round(grade);

    if (rgrade < 1)
        printf("Before Grade 1\n");
    else if (rgrade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", rgrade);
}
