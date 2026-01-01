#include <stdio.h>

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
    printf("%d steps are required to reach 1.\n", step);
    return 0;
}

int steps(long start) {
    int nsteps = 0;

    while (start != 1) {
        printf("%ld -> ", start);
        if (start % 2 == 0) {
            start /= 2;
        } else {
            start = 1 + 3 * start;
        }
        nsteps++;
    }

    printf("%ld -> Reached 1!\n", start);
    return nsteps;
}
