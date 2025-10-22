#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

int pop(void);
void push(int);
void stack_underflow(void);
void stack_overflow(void);

int peek(void);
size_t stack_size(void);
bool is_empty(void);
bool is_full(void);
int search(int);

int* create_stack(void);
int* copy_stack(int*);
void clear_stack(void);

#endif