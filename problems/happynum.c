/*
    A number is considered “happy” if, when you repeatedly replace it with the
    sum of the squares of its digits, you eventually reach the number 1. If this
    process results in an endless cycle that does not include 1, then the number
    is called an “unhappy number” or a “sad number.”
*/
#include <stdint.h>
#include <stdio.h>

int seenarr[64] = {4, 9, 16, 25, 36, 64, 81};
int seen = 7;  // Number of sums combination seen

int alreadyexists(int num) {
    for (int i = 0; i < seen; i++) {
        if (num == seenarr[i]) {
            return 1;
        }
        continue;
    }
    return 0;
}

int sumOfSquares(int num) {
    int sum = 0;
    while (num != 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

int ishappy(int num) {
    int sum = sumOfSquares(num);

    if (sum == 1) {
        return 1;  // Return one if it enters the list of 1
    } else {
        if (alreadyexists(sum)) {
            return 0;
        } else {
            if (seen < 64) {
                printf("%d\n", sum);
                seenarr[seen] = sum;
                seen++;
            } else {
                // Exceeded storage for seen sums, treat as unhappy to avoid
                // overflow
                printf("Wow, remember this number like 64 unique sums?");
                return 0;
            }

            //* Unexpected recursion
            return ishappy(sum);
        }
    }
}

int main(void) {
    printf("Enter the number: ");
    int num = 0;
    scanf("%d", &num);

    if (ishappy(num)) {
        printf("This number is happy.\n");
    } else {
        printf("This number couldn't be anymore sad and disappointing.\n");
    }

    return 0;
}
