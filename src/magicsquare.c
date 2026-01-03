#include <stdio.h>

void outSq(int n, int magicSq[n][n]) {
    printf("\nMagic square of %d.\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("\033[33m%3d\033[0m ", magicSq[i][j]);
        }
        printf("\n");
    }
}

void initSq(int n, int magicSq[n][n]) {
    // Required cause can't initialize variable array the normal way
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSq[i][j] = 0;
        }
    }
}

void fillSq(int n, int magicSq[n][n]) {
    int a = 1;  // From a to n^2
    for (int i = 0, j = n / 2; a <= (n * n); a++) {
        magicSq[i][j] = a;
        i--, j++;  // ex: (0, 3) -> (-1, 4)

        // Wrapping logic
        if (i < 0) i = n - 1;   // i: leaves from top returns from bottom
        if (j > n - 1) j -= n;  // j: leaves from right returns from left

        // If next filled, drop below
        if (magicSq[i][j] != 0) {
            i += 2;
            j--;
        }

        // 2nd Wrapping logic (caused by dropping after checking occupancy)
        if (i > n - 1) i -= n;  // i: leaves from bottom returns from top
        if (j < 0) j = n - 1;   // j: leaves from left returns from right

        //! Logic trap (4, 0) -> (6, -1) -> (0, 4)
        // Fix: use subtraction to remove out of bounds, instead of i/j=0
    }
}

int main(void) {
    // Makes magic square using the Siamese Method
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    int n = 0;
    scanf("%d", &n);
    while (n % 2 == 0 || n < 0 || n > 99) {
        printf("\nC'mon don't ruin the fun. Again! ");
        scanf("%d", &n);
    }
    int magicSq[n][n];
    initSq(n, magicSq);
    fillSq(n, magicSq);
    outSq(n, magicSq);

    return 0;
}
