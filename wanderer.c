// #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creating bool type
#define true 1
#define false 0
#define bool int

// Global variables
char PATH[10][10];
bool CAN_MOVE = true;

void createPath(char path[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            path[i][j] = '.';
        }
    }
}

void layPath(char path[10][10]) {
    for (int i = 0; i < 10; i++) {     // Looping thru rows
        for (int j = 0; j < 10; j++) { // Looping thru columns
            printf("%c  ", path[i][j]);
        }
        printf("\n");
    }
}

bool checkDirection(int x, int y) {
    if (!(x >= 0 && y >= 0 && x < 10 && y < 10)) {
        return false; // Wanderer out of bounds
    } else if (PATH[x][y] != '.') {
        return false; // Coordinate was already covered
    } else {
        return true;
    }
}

bool canMove(int x, int y) {
    bool left = (y <= 0) || (PATH[x][y - 1] != '.');
    bool right = (y >= 9) || (PATH[x][y + 1] != '.');
    bool up = (x <= 0) || (PATH[x - 1][y] != '.');
    bool down = (x >= 9) || (PATH[x + 1][y] != '.');

    if (left && right && up && down) {
        return false; // Wanderer is boxed in
    } else {
        return true;
    }
}

void move(int *x, int *y, char plate) {
    // 0 - Left, 1 - Down, 2 - Up, 3 - Right

    int tx = *x, ty = *y;
    bool valid = false;
    while (!valid) {
        int direction = rand() % 4;
        switch (direction) {
        case 0:
            ty--;
            break;
        case 1:
            tx++;
            break;
        case 2:
            tx--;
            break;
        case 3:
            ty++;
            break;
        }
        if (!(valid = checkDirection(tx, ty))) {
            tx = *x, ty = *y;
        }
    }

    CAN_MOVE = canMove(tx, ty);
    *x = tx, *y = ty;
    PATH[*x][*y] = plate;
}

int main(void) {
    srand(time(NULL));
    createPath(PATH);

    int x = rand() % 10, y = rand() % 10;
    char current = 'A';

    while (current <= 'Z') {
        move(&x, &y, current);
        current++;
        if (!CAN_MOVE) {
            printf("Wanderer was stupid enough to get struck.\n\n");
            break;
        } else if (current == 'Z') {
            printf("Wanderer has finished his chronic wandering.\n\n");
        }
    }

    layPath(PATH);
    return 0;
}
