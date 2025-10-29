#include "../include/stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void stack_underflow(void) {
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

bool is_empty(_stack_t* stack) {
    if (stack->len <= 0) {
        return true;
    } else {
        return false;
    }
}

bool is_full(_stack_t* stack) {
    if (stack->len >= stack->size) {
        return true;
    } else {
        return false;
    }
}

_stack_t* create_stack(size_t size) {
    _stack_t* rs = malloc(sizeof(_stack_t));  // rs for return stack
    rs->size = size;
    rs->cont = malloc(size * sizeof(void*));
    rs->len = 0;

    return rs;
}

_stack_t* copy_stack(_stack_t* stack) {
    _stack_t* copied = create_stack(stack->size);
    copied->len = stack->len;

    for (size_t i = 0; i < stack->len; i++) {
        copied->cont[i] = stack->cont[i];
    }
    return copied;
}

void clear_stack(_stack_t* stack) {
    // Free each pointer stored in the stack
    for (size_t i = 0; i < stack->len; i++) {
        free(stack->cont[i]);
    }
    free(stack->cont);
    free(stack);
}

void* peek(_stack_t* stack) {
    if (is_empty(stack)) {
        stack_underflow();
        return NULL;
    }

    int top = stack->len - 1;
    return stack->cont[top];
}

void push(_stack_t* stack, void* item) {
    if (!stack) return;
    if (is_full(stack)) stack_overflow();

    size_t top = stack->len++;
    stack->cont[top] = item;
    // printf("Pushed %d.\n", operand);
}

void* pop(_stack_t* stack) {
    if (!stack) return NULL;
    if (is_empty(stack)) {
        stack_underflow();
        return NULL;
    }

    int top = --(stack->len);
    void* item = stack->cont[top];
    // Set to NULL to help catch bugs related to dangling pointers.
    stack->cont[top] = NULL;
    // printf("Popped %d.\n", num);
    return item;
}

int search(_stack_t* stack, void* item) {
    for (int i = 0; i < stack->len; i++) {
        if (stack->cont[i] == item) {  // pointer comparison
            return i;
        }
    }

    return -1;
}

int search_with_cmp(_stack_t* stack, void* item, int (*cmp)(void*, void*)) {
    for (int i = 0; i < stack->len; i++) {
        if (cmp(stack->cont[i], item) == 0) {
            return i;
        }
    }
    return -1;
}
