#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

typedef struct {
    SinglyLinkedList list;
} Stack; 

void stack_init(Stack *stack, size_t elem_size);
void stack_free(Stack *stack, void (*free_func)(void *));
bool stack_push(Stack *stack, void *data);
bool stack_pop(Stack *stack, void (*free_func)(void *));
void *stack_top(Stack *stack);
bool stack_empty(Stack *stack);
size_t stack_size(Stack *stack);

#endif // STACK_H