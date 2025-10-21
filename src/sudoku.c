#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

int sudoku_grid[9][9] = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0},
};

bool fillsudoku(void);
bool islegalmove(point_t, int);
void markspot(int[][9], point_t, int);
void putgrid(int[][9]);

int main(void) {
    fillsudoku();
    putgrid(sudoku_grid);
    return 0;
}

void putgrid(int grid[][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("------+-------+------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void markspot(int grid[][9], point_t pt, int num) {
    grid[pt.x][pt.y] = num;  // pt.x is row (0-8), pt.y is column (0-8)
}

bool fillsudoku(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku_grid[i][j] == 0) {
                for (int n = 1; n < 10; n++) {
                    point_t candidate = {i, j};
                    if (islegalmove(candidate, n)) {
                        markspot(sudoku_grid, candidate, n);
                        if (fillsudoku()) {
                            return true;
                        }
                        markspot(sudoku_grid, candidate, 0);
                    }
                }
                return false;
            }
        }
    }

    return true;  // Sudoku solved
}

bool islegalmove(point_t pt, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku_grid[pt.x][i] == num) {
            // Check the row (pt.x) for duplicates.
            return false;
        }
        if (sudoku_grid[i][pt.y] == num) {
            // Check the column (pt.y) for duplicates.
            return false;
        }
    }

    int box_x = pt.x - (pt.x % 3);
    int box_y = pt.y - (pt.y % 3);
    point_t box_corner = {box_x, box_y};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku_grid[box_corner.x + i][box_corner.y + j] == num) {
                // Check the 3x3 box for duplicates.
                return false;
            }
        }
    }

    return true;  // Viable position to place 'num' in the grid at 'pt(x, y)'.
}
