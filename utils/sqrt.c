#include "../include/sqrt.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SQRT_EPSILON 0.00001f  // degree of precision

float sqrt_srch(float num) {
    if (num < 0) return NAN;
    if (num == 0) return 0;

    float low = 0.0f;              // bit manipulation can only be
    float high = num;              // performed on integer types
    float epsilon = SQRT_EPSILON;  // error of 10^-5

    if (num < 1) {
        high = 1.0f;  // root 0.025 = 0.5
    }

    float mid;
    while ((high - low) > epsilon) {
        mid = low + ((high - low) / 2.0f);
        if ((mid * mid) > num) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return mid;  // calculated sqrt
}

float sqrt_quake(float num) {
    if (num < 0) return NAN;
    if (num == 0) return 0;

    uint32_t bits;
    memcpy(&bits, &num, 4);  // copy 4 bytes from address of num to i
    uint32_t quake = 0x5f3759DF;

    // This line applies a magic constant and bit manipulation to approximate the inverse square root,
    // exploiting properties of floating-point representation for a fast initial guess.
    float root;
    bits = quake - (bits >> 1);
    memcpy(&root, &bits, 4);

    float epsilon = SQRT_EPSILON;
    double prev, droot = (double) root;

    do {
        prev = droot;
        droot = droot * (1.5f - 0.5f * num * droot * droot);
    } while (fabs(droot - prev) > epsilon);

    return num * droot;
}

float sqrt_nwtn(float num) {
    if (num < 0) return NAN;
    if (num == 0) return 0;

    // Guessing root using bit manipulation
    uint32_t bits;
    memcpy(&bits, &num, 4);
    bits = 0x1fbd1df5 + (bits >> 1);
    float guess;
    memcpy(&guess, &bits, 4);

    double epsilon = SQRT_EPSILON;  // degree of precision
    double prev, curr = guess;

    do {
        prev = curr;  // prev of curr before NR iteration
        curr = 0.5f * (prev + (num / prev));
    } while (fabs(prev - curr) > epsilon);

    return curr;
}