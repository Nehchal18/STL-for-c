#include "../headers/queue.h"

void queue_init(Queue *queue, size_t elem_size) {
    singly_list_init(&queue->list, elem_size);
}

void queue_free(Queue *queue, void (*free_func)(void *)) {
    singly_list_free(&queue->list, free_func);
}

bool queue_enqueue(Queue *queue, void *data) {
    return singly_list_insert(&queue->list, singly_list_size(&queue->list), data);
}

bool queue_dequeue(Queue *queue, void (*free_func)(void *)) {
    return singly_list_remove(&queue->list, 0, free_func);
}

void *queue_front(Queue *queue) {
    return singly_list_get(&queue->list, 0);
}

bool queue_empty(Queue *queue) {
    return singly_list_empty(&queue->list);
}

size_t queue_size(Queue *queue) {
    return singly_list_size(&queue->list);
}

void deque_init(Deque *deque, size_t elem_size) {
    doubly_list_init(&deque->list, elem_size);
}

void deque_free(Deque *deque, void (*free_func)(void *)) {
    doubly_list_free(&deque->list, free_func);
}

bool deque_push_front(Deque *deque, void *data) {
    return doubly_list_insert(&deque->list, 0, data);
}

bool deque_push_back(Deque *deque, void *data) {
    return doubly_list_insert(&deque->list, doubly_list_size(&deque->list), data);
}

bool deque_pop_front(Deque *deque, void (*free_func)(void *)) {
    return doubly_list_remove(&deque->list, 0, free_func);
}

bool deque_pop_back(Deque *deque, void (*free_func)(void *)) {
    return doubly_list_remove(&deque->list, doubly_list_size(&deque->list) - 1, free_func);
}

void *deque_front(Deque *deque) {
    return doubly_list_get(&deque->list, 0);
}

void *deque_back(Deque *deque) {
    return doubly_list_get(&deque->list, doubly_list_size(&deque->list) - 1);
}

bool deque_empty(Deque *deque) {
    return doubly_list_empty(&deque->list);
}

size_t deque_size(Deque *deque) {
    return doubly_list_size(&deque->list);
}
