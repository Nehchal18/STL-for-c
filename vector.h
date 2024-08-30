#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the vector structure
typedef struct {
    int *data;           // Pointer to the data array
    size_t size;         // Number of elements currently in the vector
    size_t capacity;     // Total capacity of the vector
} vector_int;

// Function prototypes

// Initializes the vector with an initial capacity of 4
void vector_init(vector_int *v);

// Resizes the vector to a new capacity
void vector_int_resize(vector_int *vec, size_t new_capacity);

// Adds an element to the end of the vector
void vector_int_push_back(vector_int *vec, int value);

// Removes the last element of the vector and reduces capacity if necessary
void vector_int_pop_back(vector_int *vec);

// Returns the first element of the vector
int vector_front(vector_int *v);

// Returns the last element of the vector
int vector_back(vector_int *v);

// Returns a pointer to the first element in the vector
int* vector_begin(vector_int *v);

// Returns a pointer to the element following the last element in the vector
int* vector_end(vector_int *v);

// Retrieves the element at a specific index
int vector_int_get(vector_int *vec, size_t index);

// Checks if the vector is empty
bool vector_int_empty(vector_int *vec);

// Finds the index of a specific value in the vector
int vector_int_find(vector_int *vec, int value);

// Reverses the elements of the vector
void vector_int_reverse(vector_int *vec);

// Returns the current size of the vector
size_t vector_int_size(vector_int *vec);

// Returns the current capacity of the vector
size_t vector_int_capacity(vector_int *vec);

// Clears all elements in the vector
void vector_int_clear(vector_int *vec);

// Frees the memory allocated for the vector
void vector_free(vector_int *v);
