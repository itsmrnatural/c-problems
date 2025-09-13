#include <math.h>
#include <stdio.h>

int isarmstrong(long num) {
    int place;
    int digits[16];
    int tnum = num;

    for (place = 0; tnum != 0; place++) {
        digits[place] = tnum % 10;
        tnum /= 10;
    }

    long armstrong = 0;
    for (int i = 0; i < place; i++) {
        armstrong += pow(digits[i], place);
    }

    return num == armstrong;
}

int main(void) {
    long num;
    printf("Enter an armstrong number: ");
    scanf("%ld", &num);

    while (num <= 0) {
        printf("I guess you can try again. ");
        scanf("%ld", &num);
    }

    if (isarmstrong(num)) {
        printf("This number checks out!\n");
    } else {
        printf("This number isn't armstrong.\n");
    }

    return 0;
}