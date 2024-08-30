#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
    // void (*vector_push_back)(vector_int , int );
} vector_int;


void vector_init(vector_int *v) {
    v->size = 0;
    v->capacity = 4;  // Initial capacity
    v->data = malloc(v->capacity * sizeof(int));
    if (v->data == NULL) {
        perror("Failed to initialize vector");
        exit(EXIT_FAILURE);
    }
}

void vector_int_resize(vector_int *vec, size_t new_capacity) {
    int *new_data = (int *)realloc(vec->data, new_capacity * sizeof(int));
    if (!new_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    vec->data = new_data;
    vec->capacity = new_capacity;
}

void vector_int_push_back(vector_int *vec, int value) {
    if (vec->size == vec->capacity) {
        vector_int_resize(vec, vec->capacity * 2);
    }
    vec->data[vec->size++] = value;
}

void vector_int_pop_back(vector_int *vec) {
    if (vec->size > 0) {
        vec->size--;

        // Reduce capacity if size is <= 1/4th of capacity
        if (vec->size <= vec->capacity / 4 && vec->capacity > 4) {
            vector_int_resize(vec, vec->capacity / 2);
        }
    }
}

int vector_front(vector_int *v) {
    if (v->size > 0) {
        return v->data[0];
    }
    perror("Vector is empty");
    exit(EXIT_FAILURE);
}

int vector_back(vector_int *v) {
    if (v->size > 0) {
        return v->data[v->size - 1];
    }
    perror("Vector is empty");
    exit(EXIT_FAILURE);
}

int* vector_begin(vector_int *v) {
    return v->data;
}

int* vector_end(vector_int *v) {
    return v->data + v->size;
}

int vector_int_get(vector_int *vec, size_t index) {
    if (index >= vec->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}

bool vector_int_empty(vector_int *vec) {
    return vec->size == 0;
}

int vector_int_find(vector_int *vec, int value) {
    for (size_t i = 0; i < vec->size; i++) {
        if (vec->data[i] == value) {
            return i;
        }
    }
    return -1;
}

void vector_int_reverse(vector_int *vec) {
    for (size_t i = 0; i < vec->size / 2; i++) {
        int temp = vec->data[i];
        vec->data[i] = vec->data[vec->size - 1 - i];
        vec->data[vec->size - 1 - i] = temp;
    }
}

size_t vector_int_size(vector_int *vec) {
    return vec->size;
}

size_t vector_int_capacity(vector_int *vec) {
    return vec->capacity;
}

void vector_int_clear(vector_int *vec) {
    vec->size = 0;
}

void vector_free(vector_int *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
int main() {
    vector_int vec;
    vector_init(&vec);

    // Test push_back and size/capacity
    printf("Pushing back elements: 10, 20, 30, 40, 50\n");
    vector_int_push_back(&vec, 10);
    vector_int_push_back(&vec, 20);
    vector_int_push_back(&vec, 30);
    vector_int_push_back(&vec, 40);
    vector_int_push_back(&vec, 50);

    printf("Vector size: %zu\n", vector_int_size(&vec));
    printf("Vector capacity: %zu\n", vector_int_capacity(&vec));

    // Test access to front and back elements
    printf("Front element: %d\n", vector_front(&vec));
    printf("Back element: %d\n", vector_back(&vec));

    // Test access by index
    printf("Element at index 2: %d\n", vector_int_get(&vec, 2));

    // Test find function
    int value_to_find = 30;
    int index = vector_int_find(&vec, value_to_find);
    if (index != -1) {
        printf("Element %d found at index %d\n", value_to_find, index);
    } else {
        printf("Element %d not found\n", value_to_find);
    }

    // Test pop_back and capacity reduction
    printf("Popping back elements\n");
    vector_int_pop_back(&vec);
    vector_int_pop_back(&vec);

    printf("Vector size after popping: %zu\n", vector_int_size(&vec));
    printf("Vector capacity after popping: %zu\n", vector_int_capacity(&vec));

    // Test reverse function
    printf("Reversing vector\n");
    vector_int_reverse(&vec);
    printf("Vector elements after reversing: ");
    for (int *it = vector_begin(&vec); it != vector_end(&vec); ++it) {
        printf("%d ", *it);
    }
    printf("\n");

    // Test clear function
    printf("Clearing vector\n");
    vector_int_clear(&vec);
    printf("Vector size after clearing: %zu\n", vector_int_size(&vec));
    printf("Is vector empty? %s\n", vector_int_empty(&vec) ? "Yes" : "No");

    // Clean up
    vector_free(&vec);

    return 0;
}