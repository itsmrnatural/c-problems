#include <stdio.h>

int STEP = 0;
int steps(long start);

int main(void) {
    long num;
    int step;

    printf("Enter the positive int: ");
    scanf("%ld", &num);
    if (num <= 0) {
        printf("C'mon be serious!\n");
        return 0;
    }

    step = steps(num);

    printf("The %d steps are required to reach 1.\n", step);
    return 0;
}

int steps(long start) {
    printf("%ld -> ", start);

    if (start == 1) {
        printf("Reached 1!\n");
    } else if (start % 2 == 0) {
        start /= 2;
        STEP++;
        steps(start);
    } else {
        start = 1 + 3 * start;
        STEP++;
        steps(start);
    }

    return STEP;
}