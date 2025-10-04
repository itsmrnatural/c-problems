#include <stdio.h>

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

int color_code(resistor_band_t color1, resistor_band_t color2);
resistor_band_t* colors(void);

// File starts here

resistor_band_t resistorColors[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

int main(void) {
    return 0;
}

int color_code(resistor_band_t color1, resistor_band_t color2) {
    return color1 * 10 + color2;
}

resistor_band_t* colors(void)  // This means this function returns a pointer to the resistor_band_t "type".
{
    return resistorColors;
}