#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION,
} atk_status;

typedef struct {
    uint8_t row;
    uint8_t col;
} position;

struct Board {
    size_t n;
    size_t used;
    char** grid;
};

atk_status relation(uint8_t n, position q1, position q2) {
    if (q1.row >= n || q2.row >= n) {
        return INVALID_POSITION;
    } else if (q1.col >= n || q2.col >= n) {
        return INVALID_POSITION;
    }
    // else if (q1.row == q2.row && q1.col == q2.col) {
    //     return INVALID_POSITION;
    // }

    if (q1.row == q2.row) {
        return CAN_ATTACK;
    } else if (q1.col == q2.col) {
        return CAN_ATTACK;
    } else if (abs(q1.row - q2.row) == abs(q1.col - q2.col)) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}
/* Above code modified from src/chesspos.c */

bool queen_at(struct Board* board, position queen) {
    /* Unused */
    size_t size = board->n;
    if (relation(size, queen, queen) == INVALID_POSITION) {
        fprintf(stderr, "Queen should be at a valid position.");
        return true;  // Pretend queen is there
    }

    if (board->grid[queen.row][queen.col] == 'Q') {
        return true;
    }
    return false;
}

bool can_be_attacked(struct Board* board, position queen) {
    size_t size = board->n;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            position candidate = {.row = i, .col = j};
            if (!queen_at(board, candidate)) {
                continue;
            }

            if (relation(size, queen, candidate) != CAN_NOT_ATTACK) {
                return true;
            }
        }
    }
    return false;
}

void setup_board(struct Board* board) {
    size_t size = board->n;
    board->grid = malloc(size * sizeof(char*));
    for (size_t i = 0; i < size; i++) {
        board->grid[i] = malloc(size * sizeof(char));
        for (size_t j = 0; j < size; j++) {
            board->grid[i][j] = '.';
        }
    }
}

void clean_board(struct Board* board) {
    size_t size = board->n;
    for (size_t i = 0; i < size; i++) {
        free(board->grid[i]);
    }
    free(board->grid);
}

void place_queen(struct Board* board, position queen) {
    size_t size = board->n;
    if (relation(size, queen, queen) == INVALID_POSITION) {
        fprintf(stderr, "Cannot place queen out of the board.");
        return;
    }

    size_t row = queen.row;
    size_t col = queen.col;
    board->grid[row][col] = 'Q';
    board->used++;

    #ifdef DEBUG
    printf("Placed (%zu, %zu)\n", row, col);
    #endif
}

void remove_queen(struct Board* board, position queen) {
    size_t size = board->n;
    if (relation(size, queen, queen) == INVALID_POSITION) {
        fprintf(stderr, "Cannot remove queen from out of the board.");
        return;
    }
    
    size_t row = queen.row;
    size_t col = queen.col;
    board->grid[row][col] = '.';
    board->used--;

    #ifdef DEBUG
    printf("Removed (%zu, %zu)\n", row, col);
    #endif
}

bool setup_queens(struct Board* board) {
    if (board->used == board->n) return true;

    size_t size = board->n;
    size_t row = board->used;  // Current row to place queen
    for (size_t col = 0; col < size; col++) {
        position candidate = {.row = row, .col = col};
        if (can_be_attacked(board, candidate)) {
            continue;
        }

        place_queen(board, candidate);
        if (setup_queens(board)) return true;
        remove_queen(board, candidate);
    }
    return false;
}

void print_board(struct Board* board) {
    size_t size = board->n;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    srand((unsigned) time(NULL));
    struct Board board;
    struct Board* p_board = &board;
    printf("How many queens (n) should be place on a NxN board? ");
    scanf("%zu", &board.n);

    // First queen is randomly place cause why not.
    size_t size = p_board->n;
    while (board.n != board.used) {
        board.used = 0;
        setup_board(p_board);
        position first_queen = {
            .row = rand() % size,
            .col = rand() % size,
        };
        place_queen(p_board, first_queen);
        setup_queens(p_board);
        #ifdef DEBUG
        if (board.n != board.used) {
            printf("\nAll queens couldn't be placed successfully in this instance.\n");
        }
        #endif
    }

    print_board(p_board);
    clean_board(p_board);
    return 0;
}
