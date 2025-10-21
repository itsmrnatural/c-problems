#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
char path[10][10];
bool can_move = true;

void createPath(char path[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            path[i][j] = '.';
        }
    }
}

void layPath(char path[10][10]) {
    for (int i = 0; i < 10; i++) {      // Looping thru rows
        for (int j = 0; j < 10; j++) {  // Looping thru columns
            printf("%c  ", path[i][j]);
        }
        printf("\n");
    }
}

bool checkDirection(int x, int y) {
    if (!(x >= 0 && y >= 0 && x < 10 && y < 10)) {
        return false;  // Wanderer out of bounds
    } else if (path[x][y] != '.') {
        return false;  // Coordinate was already covered
    } else {
        return true;
    }
}

bool canMove(int x, int y) {
    bool canLeft = (y > 0) && (path[x][y - 1] == '.');
    bool canRight = (y < 9) && (path[x][y + 1] == '.');
    bool canUp = (x > 0) && (path[x - 1][y] == '.');
    bool canDown = (x < 9) && (path[x + 1][y] == '.');

    if (!canLeft && !canRight && !canUp && !canDown) {
        return false;  // Wanderer is boxed in
    } else {
        return true;
    }
}

void move(int* x, int* y, char marker) {
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

    can_move = canMove(tx, ty);
    *x = tx, *y = ty;
    path[*x][*y] = marker;
}

int main(void) {
    srand(time(NULL));
    createPath(path);

    int x = rand() % 10, y = rand() % 10;
    char current = 'A';

    while (current <= 'Z') {
        move(&x, &y, current);
        current++;
        if (!can_move) {
            printf("Wanderer was stupid enough to get struck.\n\n");
            break;
        } else if (current == 'Z') {
            printf("Wanderer has finished his chronic wandering.\n\n");
        }
    }

    layPath(path);
    return 0;
}
