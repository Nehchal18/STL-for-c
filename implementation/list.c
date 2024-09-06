#include "../headers/list.h"

void singly_list_init(SinglyLinkedList *list, size_t elem_size) {
    list->head = NULL;
    list->size = 0;
    list->elem_size = elem_size;
}

void singly_list_free(SinglyLinkedList *list, void (*free_func)(void *)) {
    singly_list_clear(list, free_func);
}

bool singly_list_insert(SinglyLinkedList *list, size_t index, void *data) {
    if (index > list->size) {
        return false;
    }

    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    if (!new_node) {
        return false;
    }

    new_node->data = malloc(list->elem_size);
    if (!new_node->data) {
        free(new_node);
        return false;
    }
    memcpy(new_node->data, data, list->elem_size);

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        SNode *current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    list->size++;
    return true;
}

bool singly_list_remove(SinglyLinkedList *list, size_t index, void (*free_func)(void *)) {
    if (index >= list->size || list->head == NULL) {
        return false;
    }

    SNode *current = list->head;
    if (index == 0) {
        list->head = current->next;
    } else {
        SNode *prev = NULL;
        for (size_t i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }

    if (free_func) {
        free_func(current->data);
    }
    free(current->data);
    free(current);
    list->size--;
    return true;
}

void *singly_list_get(SinglyLinkedList *list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }

    SNode *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void singly_list_clear(SinglyLinkedList *list, void (*free_func)(void *)) {
    SNode *current = list->head;
    while (current != NULL) {
        SNode *next_node = current->next;
        if (free_func) {
            free_func(current->data);
        }
        free(current->data);
        free(current);
        current = next_node;
    }
    list->head = NULL;
    list->size = 0;
}

bool singly_list_empty(SinglyLinkedList *list) {
    return list->size == 0;
}

size_t singly_list_size(SinglyLinkedList *list) {
    return list->size;
}

void doubly_list_init(DoublyLinkedList *list, size_t elem_size) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->elem_size = elem_size;
}

void doubly_list_free(DoublyLinkedList *list, void (*free_func)(void *)) {
    doubly_list_clear(list, free_func);
}

bool doubly_list_insert(DoublyLinkedList *list, size_t index, void *data) {
    if (index > list->size) {
        return false;
    }

    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    if (!new_node) {
        return false;
    }

    new_node->data = malloc(list->elem_size);
    if (!new_node->data) {
        free(new_node);
        return false;
    }
    memcpy(new_node->data, data, list->elem_size);

    if (index == 0) {
        new_node->next = list->head;
        new_node->prev = NULL;
        if (list->head) {
            list->head->prev = new_node;
        }
        list->head = new_node;
        if (list->size == 0) {
            list->tail = new_node;
        }
    } else if (index == list->size) {
        new_node->next = NULL;
        new_node->prev = list->tail;
        if (list->tail) {
            list->tail->next = new_node;
        }
        list->tail = new_node;
        if (list->size == 0) {
            list->head = new_node;
        }
    } else {
        DNode *current = list->head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
    }

    list->size++;
    return true;
}

bool doubly_list_remove(DoublyLinkedList *list, size_t index, void (*free_func)(void *)) {
    if (index >= list->size || list->head == NULL) {
        return false;
    }

    DNode *current = list->head;
    if (index == 0) {
        list->head = current->next;
        if (list->head) {
            list->head->prev = NULL;
        }
        if (free_func) {
            free_func(current->data);
        }
        free(current->data);
        free(current);
        if (list->size == 1) {
            list->tail = NULL;
        }
    } else if (index == list->size - 1) {
        current = list->tail;
        list->tail = current->prev;
        if (list->tail) {
            list->tail->next = NULL;
        }
        if (free_func) {
            free_func(current->data);
        }
        free(current->data);
        free(current);
    } else {
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (free_func) {
            free_func(current->data);
        }
        free(current->data);
        free(current);
    }

    list->size--;
    return true;
}

void *doubly_list_get(DoublyLinkedList *list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }

    DNode *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void doubly_list_clear(DoublyLinkedList *list, void (*free_func)(void *)) {
    DNode *current = list->head;
    while (current != NULL) {
        DNode *next_node = current->next;
        if (free_func) {
            free_func(current->data);
        }
        free(current->data);
        free(current);
        current = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

bool doubly_list_empty(DoublyLinkedList *list) {
    return list->size == 0;
}

size_t doubly_list_size(DoublyLinkedList *list) {
    return list->size;
}