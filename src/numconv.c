#include <math.h>
#include <stdio.h>

double bin(double number) {
    int int_part = (int) number;
    double float_part = number - int_part;

    int renum = 0;
    for (int i = 0; int_part != 0; i++) {
        int rem = int_part % 2;
        renum += (pow(10, i) * rem);

        int_part /= 2;
    }

    double refloat = 0;
    for (int i = 1; float_part != 0 && i <= 6; i++) {
        float_part *= 2;
        int non_float = (int) float_part;
        float_part -= non_float;
        refloat += (pow(10, -i) * non_float);
    }

    return renum + refloat;
}

int main(void) {
    printf("Enter number to convert to binary: ");

    double number;
    scanf("%lf", &number);

    double ans = bin(number);
    printf("The binary equivalent is %lf.\n", ans);
    return 0;
}
