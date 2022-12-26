#include <stdlib.h>
#include "baseQueue.h"

typedef struct Deque {
    I *data;
    size_t size;
} Deque_t;

Deque_t *createDeque() {
    Deque_t *deque = NULL;
    deque = malloc(sizeof(Deque_t));
    if (deque == NULL) {
        exit(OUT_OF_MEMORY);
    }
    deque->size = 0;
    deque->data = malloc(deque->size * sizeof(I));
    return deque;
}

void deleteDeque(Deque_t *deque) {
    free(deque->data);
    free(deque);
    deque = NULL;
}

void returnDequeOverflow(const I *data) {
    if (data == NULL) {
        exit(QUEUE_OVERFLOW);
    }
}

void enqueueStart(Deque_t *deque, const I value) {
    deque->size++;
    I *data = NULL;
    data = malloc(deque->size * sizeof(I));
    returnDequeOverflow(data);
    data[0] = value;
    for (int i = 1; i < deque->size; i++) {
        data[i] = deque->data[i - 1];
    }
    free(deque->data);
    deque->data = data;
}

void enqueueEnd(Deque_t *deque, const I value) {
    deque->size++;
    deque->data = realloc(deque->data, deque->size * sizeof(I));
    returnDequeOverflow(deque->data);
    deque->data[deque->size - 1] = value;
}

void returnDequeUnderflow(const size_t size) {
    if (size == 0) {
        exit(QUEUE_UNDERFLOW);
    }
}

I dequeueStart(Deque_t *deque) {
    returnDequeUnderflow(deque->size);
    deque->size--;
    I value = *deque->data;
    deque->data = &(deque->data[1]);
    return value;
}

I dequeueEnd(Deque_t *deque) {
    returnDequeUnderflow(deque->size);
    deque->size--;
    I value = deque->data[deque->size];
    deque->data = realloc(deque->data, deque->size * sizeof(I));
    return value;
}

I peekStart(Deque_t *deque) {
    returnDequeUnderflow(deque->size);
    return *deque->data;
}

I peekEnd(Deque_t *deque) {
    returnDequeUnderflow(deque->size);
    return deque->data[deque->size - 1];
}

size_t count(Deque_t *deque) {
    return deque->size;
}