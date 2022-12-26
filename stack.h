#include <stdlib.h>
#include "global.h"

#define STACK_OVERFLOW -101
#define STACK_UNDERFLOW -102

typedef struct Stack {
    I *data;
    size_t size;
} Stack_t;

Stack_t *createStack() {
    Stack_t *stack = NULL;
    stack = malloc(sizeof(Stack_t));
    if (stack == NULL) {
        exit(OUT_OF_MEMORY);
    }
    stack->size = 0;
    stack->data = malloc(stack->size * sizeof(I));
    return stack;
}

void deleteStack(Stack_t *stack) {
    free(stack->data);
    free(stack);
    stack = NULL;
}

void resizeStack(Stack_t *stack) {
    stack->data = realloc(stack->data, stack->size * sizeof(I));
}

void push(Stack_t *stack, const I value) {
    stack->size++;
    resizeStack(stack);
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size - 1] = value;
}

void returnStackUnderflow(const size_t size) {
    if (size == 0) {
        exit(STACK_UNDERFLOW);
    }
}

I pop(Stack_t *stack) {
    returnStackUnderflow(stack->size);
    stack->size--;
    I value = stack->data[stack->size];
    resizeStack(stack);
    return value;
}

I peek(Stack_t *stack) {
    returnStackUnderflow(stack->size);
    return stack->data[stack->size - 1];
}

size_t count(Stack_t *stack) {
    return stack->size;
}