#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Macros
#define MAX_SIZE 16

// Global variables
int STACK[MAX_SIZE] = {0};
int TOP = -1;  // Need to start with -1 cause the first element pushed will be indexed 0.

// Function prototypes
void push(int operand);
int pop(void);
void stack_underflow(void);
void stack_overflow(void);
void show_result(void);
void hopper(char ch);
void read(void);
void evaluate(char operator);
bool is_valid_operator(char ch);

int main(void) {
    // Sadly all the logic was offloaded to other functions
    // that's why main looks so lonely right now... truly
    // saddening
    read();
    return 0;
}

void read(void) {
    printf("Enter an RPN expression: ");
    char ch = '\0';
    int operand;

    while (ch != '\n') {
        if (scanf(" %d", &operand)) {
            push(operand);
        } else {
            scanf(" %c", &ch);
            if (ch != '\n') hopper(ch);
        }
    }
}

void hopper(char ch) {
    if (is_valid_operator(ch)) {
        evaluate(ch);
    } else {
        printf("Bad character entered. Program terminated.\n");
        exit(EXIT_FAILURE);
    }
}

void stack_underflow(void) {
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

bool is_valid_operator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') {
        return true;
    } else {
        return false;
    }
}

void show_result(void) {
    int result = STACK[TOP];
    printf("Value of expression: %d\n", result);
    read();
}

void evaluate(char operator) {
    if (operator== '=') {
        show_result();
    } else if (operator== '+') {
        int a = pop();
        int b = pop();

        push(b + a);
    } else if (operator== '-') {
        int a = pop();
        int b = pop();

        push(b - a);
    } else if (operator== '*') {
        int a = pop();
        int b = pop();

        push(b * a);
    } else if (operator== '/') {
        int a = pop();
        if (a == 0) {
            printf("Error: Division by zero!\n");
            exit(EXIT_FAILURE);
        }
        int b = pop();

        push(b / a);
    } else if (operator== '%') {
        int a = pop();
        if (a == 0) {
            printf("Error: Modulo by zero!\n");
            exit(EXIT_FAILURE);
        }
        int b = pop();

        push(b % a);
    }
}

void push(int operand) {
    if (TOP >= MAX_SIZE - 1) {
        stack_overflow();
        return;
    }

    TOP++;
    STACK[TOP] = operand;
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
