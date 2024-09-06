#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "vector.h"

typedef struct {
    vector vec;                              // Vector to store heap elements
    int (*compare)(const void*, const void*); // Comparison function to maintain heap order
} heap;
typedef heap priority_queue;

void heap_init(heap *h, size_t elem_size, int (*compare)(const void*, const void*));
void heapify_up(heap *h, size_t index);
void heapify_down(heap *h, size_t index);
void heap_push(heap *h, const void *value);
void heap_pop(heap *h);
void *heap_top(heap *h);
bool vector_is_heap(vector *v, int (*compare)(const void*, const void*));
void heap_free(heap *h);

void priority_queue_init(priority_queue *pq, size_t elem_size, int (*compare)(const void*, const void*));
void priority_queue_push(priority_queue *pq, const void *value);
void priority_queue_pop(priority_queue *pq);
void *priority_queue_top(priority_queue *pq);
bool priority_queue_empty(priority_queue *pq);
void priority_queue_free(priority_queue *pq);

#endif // PRIORITY_QUEUE_H