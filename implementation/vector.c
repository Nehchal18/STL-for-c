#include "../headers/vector.h"

void vector_init(vector *v, size_t elem_size) {
    if(elem_size == 0) {
        fprintf(stderr, "Element size must be greater than 0\n");
        exit(EXIT_FAILURE);
    }
    v->size = 0;
    v->capacity = 4;  // Initial capacity
    v->elem_size = elem_size;

    v->data = malloc(v->capacity * elem_size);
    if (v->data == NULL) {
        perror("Failed to initialize vector");
        exit(EXIT_FAILURE);
    }
}

void vector_resize(vector *v, size_t new_capacity) {
    void *new_data = realloc(v->data, new_capacity * v->elem_size);
    if (!new_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    v->data = new_data;
    v->capacity = new_capacity;
}

void vector_push_back(vector *v, const void *value) {
    if (v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }

    void *target = (char *)v->data + v->size * v->elem_size;
    memcpy(target, value, v->elem_size);
    v->size++;
}

void vector_pop_back(vector *v) {
    if (v->size > 0) {
        v->size--;

        // Reduce capacity if size is <= 1/4th of capacity
        if (v->size <= v->capacity / 4 && v->capacity > 4) {
            vector_resize(v, v->capacity / 2);
        }
    }
}

void * vector_front(vector *v) {
    if (v->size > 0) {
        return (char *)v->data;
    }
    perror("Vector is empty");
    exit(EXIT_FAILURE);
}

void * vector_back(vector *v) {
    if (v->size > 0) {
        return (char *)v->data + (v->size - 1) * v->elem_size;
    }
    perror("Vector is empty");
    exit(EXIT_FAILURE);
}

void * vector_begin(vector *v) {
    return v->data;
}

void * vector_end(vector *v) {
    return (char *)v->data + v->size * v->elem_size;
}

void * vector_get(vector *vec, size_t index) {
    if (index >= vec->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return (char *)vec->data + index * vec->elem_size;
}

bool vector_empty(vector *vec) {
    return vec->size == 0;
}

size_t vector_find(vector *vec, const void *value, int (*compare)(const void*, const void*)) {
    for (size_t i = 0; i < vec->size; i++) {
        void *elem = (char *)vec->data + i * vec->elem_size;
        if (compare(elem, value) == 0) {
            return i;
        }
    }
    return (size_t)-1;
}

void vector_reverse(vector *vec) {
    for (size_t i = 0; i < vec->size / 2; i++) {
        void *left = (char *)vec->data + i * vec->elem_size;
        void *right = (char *)vec->data + (vec->size - 1 - i) * vec->elem_size;
        void *temp = malloc(vec->elem_size);
        if (!temp) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        memcpy(temp, left, vec->elem_size);
        memcpy(left, right, vec->elem_size);
        memcpy(right, temp, vec->elem_size);
        free(temp);
    }
}

size_t vector_size(vector *vec) {
    return vec->size;
}

size_t vector_capacity(vector *vec) {
    return vec->capacity;
}

void vector_clear(vector *vec) {
    vec->size = 0;
}

void vector_free(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_sort(vector *vec, void (*sort_function)(void*, size_t, size_t, int (*compare)(const void*, const void*)), int (*compare)(const void*, const void*)) {    if (vec->size > 1) {
        sort_function(vec->data, vec->size, vec->elem_size, compare);
    }
}
