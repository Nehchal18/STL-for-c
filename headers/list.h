#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Node structure for singly linked list
typedef struct SNode {
    void *data;
    struct SNode *next;
} SNode;

// Singly linked list structure
typedef struct {
    SNode *head;
    size_t size;
    size_t elem_size;
} SinglyLinkedList;

// Node structure for doubly linked list
typedef struct DNode {
    void *data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

// Doubly linked list structure
typedef struct {
    DNode *head;
    DNode *tail;
    size_t size;
    size_t elem_size;
} DoublyLinkedList;

// Singly linked list functions
void singly_list_init(SinglyLinkedList *list, size_t elem_size);
void singly_list_free(SinglyLinkedList *list, void (*free_func)(void *));
bool singly_list_insert(SinglyLinkedList *list, size_t index, void *data);
bool singly_list_remove(SinglyLinkedList *list, size_t index, void (*free_func)(void *));
void *singly_list_get(SinglyLinkedList *list, size_t index);
void singly_list_clear(SinglyLinkedList *list, void (*free_func)(void *));
bool singly_list_empty(SinglyLinkedList *list);
size_t singly_list_size(SinglyLinkedList *list);

// Doubly linked list functions
void doubly_list_init(DoublyLinkedList *list, size_t elem_size);
void doubly_list_free(DoublyLinkedList *list, void (*free_func)(void *));
bool doubly_list_insert(DoublyLinkedList *list, size_t index, void *data);
bool doubly_list_remove(DoublyLinkedList *list, size_t index, void (*free_func)(void *));
void *doubly_list_get(DoublyLinkedList *list, size_t index);
void doubly_list_clear(DoublyLinkedList *list, void (*free_func)(void *));
bool doubly_list_empty(DoublyLinkedList *list);
size_t doubly_list_size(DoublyLinkedList *list);

#endif // LIST_H