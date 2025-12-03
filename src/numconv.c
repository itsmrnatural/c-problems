#include <stdio.h>

double bin(double number) {
    int int_part = (int) number;
    double float_part = number - int_part;

    int renum = 0;
    int power_of_ten = 1;
    for (int i = 0; int_part != 0; i++) {
        int rem = int_part % 2;
        renum += (power_of_ten * rem);
        power_of_ten *= 10;
        int_part /= 2;
    }

    double refloat = 0;
    double divisor = 0.1;
    for (int i = 1; float_part != 0 && i <= 6; i++) {
        float_part *= 2;
        int non_float = (int) float_part;
        float_part -= non_float;
        refloat += (divisor * non_float);
        divisor *= 0.1;
    }

    return renum + refloat;
}

double decimal(double number) {
    int int_part = (int) number;
    double float_part = number - int_part;

    int renum = 0;
    int power_of_two = 1;
    while (int_part != 0) {
        int rem = int_part % 10;
        renum += (power_of_two * rem);
        power_of_two *= 2;
        int_part /= 10;
    }

    double refloat = 0;
    double divisor = 0.5;
    int i = 1;
    while (float_part > 1e-9 && i <= 12) {
        float_part *= 10;
        int digit = (int) float_part;
        float_part -= digit;
        refloat += (divisor * digit);
        divisor *= 0.5;
        i++;
    }

    return renum + refloat;
}

int main(void) {
    printf("Enter number to convert to decimal: ");

    double number;
    scanf("%lf", &number);

    // double ans = bin(number);
    double unans = decimal(number);
    printf("The decimal equivalent is %lf.\n", unans);
    return 0;
}
