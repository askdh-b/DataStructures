#include <stdio.h>
#include <stdlib.h>
#include "baseQueue.h"

typedef struct Queue {
    I *data;
    size_t size;
} Queue_t;

Queue_t *createQueue() {
    Queue_t *queue = NULL;
    queue = malloc(sizeof(Queue_t));
    if (queue == NULL) {
        exit(OUT_OF_MEMORY);
    }
    queue->size = 0;
    queue->data = malloc(queue->size * sizeof(I));
    return queue;
}

void deleteQueue(Queue_t *queue) {
    free(queue->data);
    free(queue);
    queue = NULL;
}

void enqueue(Queue_t *queue, const I value) {
    queue->size++;
    queue->data = realloc(queue->data, queue->size * sizeof(I));
    if (queue->data == NULL) {
        exit(QUEUE_OVERFLOW);
    }
    queue->data[queue->size - 1] = value;
}

void returnDequeUnderflow(const size_t size) {
    if (size == 0) {
        exit(QUEUE_UNDERFLOW);
    }
}

I dequeue(Queue_t *queue) {
    returnDequeUnderflow(queue->size);
    queue->size--;
    I value = *queue->data;
    queue->data = &(queue->data[1]);
    return value;
}

I peek(Queue_t *queue) {
    returnDequeUnderflow(queue->size);
    return *queue->data;
}

size_t count(Queue_t *queue) {
    return queue->size;
}