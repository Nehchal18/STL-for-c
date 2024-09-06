#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    void *data;           // Pointer to the data array
    size_t size;         // Number of elements currently in the vector
    size_t capacity;     // Total capacity of the vector
    size_t elem_size;     // Size of each element in the vector
} vector;

// Initializes the vector 
void vector_init(vector *v, size_t elem_size);

// Resizes the vector to a new capacity
void vector_resize(vector *v, size_t new_capacity);

// Adds an element to the end of the vector
void vector_push_back(vector *v, const void *value);

// Removes the last element of the vector
void vector_pop_back(vector *v);

// Returns the first element of the vector
void * vector_front(vector *v);

// Returns the last element of the vector
void * vector_back(vector *v);

// Returns a pointer to the first element in the vector
void * vector_begin(vector *v);

// Returns a pointer to the element following the last element in the vector
void * vector_end(vector *v);

// Retrieves the element at a specific index
void * vector_get(vector *vec, size_t index);

// Checks if the vector is empty
bool vector_empty(vector *vec);

// Finds the index of a specific value in the vector
size_t vector_find(vector *vec, const void *value, int (*compare)(const void*, const void*));
// Reverses the elements of the vector
void vector_reverse(vector *vec);

// Returns the current size of the vector
size_t vector_size(vector *vec);

// Returns the current capacity of the vector
size_t vector_capacity(vector *vec);

// Clears all elements in the vector
void vector_clear(vector *vec);

// Frees the memory allocated for the vector
void vector_free(vector *v);

// Sorts the elements of the vector using the specified sorting function
void vector_sort(vector *vec, void (*sort_function)(void*, size_t, size_t, int (*compare)(const void*, const void*)), int (*compare)(const void*, const void*));

#endif // VECTOR_H