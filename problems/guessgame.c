#include <stdio.h>
#include <string.h>

typedef struct {
    int lower;
    int upper;
} range_t;

void guessing(void);

int main(void) {
    printf("Think of a random number between 1-1000.\n");
    guessing();
    return 0;
}

void guessing(void) {
    int guesses = 1;
    range_t range = {.lower = 1, .upper = 1000};

    while (1) {
        if (guesses > 10) {
            printf("So, you're cheating?\n");
            break;
        }
        int guess = (range.lower + range.upper) / 2;

        printf("Is it %d?\n", guess);
        printf("Choose option (correct/lower/higher): ");
        char option[32];
        fgets(option, 8, stdin);

        if (strncmp(option, "correct", 7) == 0) {
            printf("I know right, I am great.\n");
            printf("I got it in %d guesses.\n", guesses);
            break;
        } else if (strncmp(option, "lower", 5) == 0) {
            range.upper = guess - 1;
            guesses++;
        } else if (strncmp(option, "higher", 6) == 0) {
            range.lower = guess + 1;
            guesses++;
        }

    }
}
