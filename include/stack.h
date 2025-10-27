#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    void** cont;  // same as void* stack[]
    int len;
} _stack_t;

void stack_underflow(void);
void stack_overflow(void);

void* pop(_stack_t*);
void push(_stack_t*, void*);
void* peek(_stack_t*);
bool is_empty(_stack_t*);
bool is_full(_stack_t*);
int search(_stack_t*, void*);

_stack_t* create_stack(size_t);
_stack_t* copy_stack(_stack_t*);
void clear_stack(_stack_t*);

#endif