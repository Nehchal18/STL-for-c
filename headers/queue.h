#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef struct {
    SinglyLinkedList list;
} Queue;

void queue_init(Queue *queue, size_t elem_size);
void queue_free(Queue *queue, void (*free_func)(void *));
bool queue_enqueue(Queue *queue, void *data);
bool queue_dequeue(Queue *queue, void (*free_func)(void *));
void *queue_front(Queue *queue);
bool queue_empty(Queue *queue);
size_t queue_size(Queue *queue);

typedef struct {
    DoublyLinkedList list;
} Deque;

void deque_init(Deque *deque, size_t elem_size);
void deque_free(Deque *deque, void (*free_func)(void *));
bool deque_push_front(Deque *deque, void *data);
bool deque_push_back(Deque *deque, void *data);
bool deque_pop_front(Deque *deque, void (*free_func)(void *));
bool deque_pop_back(Deque *deque, void (*free_func)(void *));
void *deque_front(Deque *deque);
void *deque_back(Deque *deque);
bool deque_empty(Deque *deque);
size_t deque_size(Deque *deque);

#endif // QUEUE_H