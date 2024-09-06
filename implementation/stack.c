#include "../headers/stack.h"

// Initialize the stack
void stack_init(Stack *stack, size_t elem_size) {
    singly_list_init(&stack->list, elem_size);
}

// free the stack
void stack_free(Stack *stack, void (*free_func)(void *)) {
    singly_list_free(&stack->list, free_func);
}

// Push an element onto the stack
bool stack_push(Stack *stack, void *data) {
    return singly_list_insert(&stack->list, 0, data);  // Insert at the head of the list
}

// Pop an element from the stack
bool stack_pop(Stack *stack, void (*free_func)(void *)) {
    return singly_list_remove(&stack->list, 0, free_func);  // Remove from the head of the list
}

// Retrieve the top element of the stack without removing it
void *stack_top(Stack *stack) {
    return singly_list_get(&stack->list, 0);  // Get the element at the head of the list
}

// Check if the stack is empty
bool stack_empty(Stack *stack) {
    return singly_list_empty(&stack->list);
}

// Get the size of the stack
size_t stack_size(Stack *stack) {
    return singly_list_size(&stack->list);
}
