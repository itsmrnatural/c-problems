#include "../include/stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Macros
#define STACK_SIZE 16

// Global variables
int STACK[STACK_SIZE] = {0};
int TOP = -1;  // Need to start with -1 cause the first element pushed will be indexed 0.

void stack_underflow(void) {
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

void push(int item) {
    if (TOP >= STACK_SIZE - 1) {
        stack_overflow();
        return;
    }

    TOP++;
    STACK[TOP] = item;
    // printf("Pushed %d.\n", operand);
}

int pop(void) {
    if (TOP < 0) {
        stack_underflow();
    }

    int num = STACK[TOP];
    STACK[TOP] = 0;
    TOP--;
    // printf("Popped %d.\n", num);
    return num;
}
