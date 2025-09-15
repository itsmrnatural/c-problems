#include <math.h>
#include <stdint.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t position) {
    float radius = sqrtf(pow(position.x, 2) + pow(position.y, 2));
    if (5 < radius && radius <= 10) {
        return 1;
    } else if (1 < radius && radius <= 5) {
        return 5;
    } else if (radius <= 1) {
        return 10;
    } else {
        return 0;
    }
}