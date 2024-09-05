#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(void *a, void *b, size_t elem_size);

int int_greater(const void *a, const void *b);
int int_lesser(const void *a, const void *b);

// Comparison functions for char
int char_greater(const void *a, const void *b);
int char_lesser(const void *a, const void *b);

// Comparison functions for float
int float_greater(const void *a, const void *b);
int float_lesser(const void *a, const void *b);

// Comparison functions for double
int double_greater(const void *a, const void *b);
int double_lesser(const void *a, const void *b);

// Comparison functions for strings
int string_greater(const void *a, const void *b);
int string_lesser(const void *a, const void *b);

void bubble_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *));
void selection_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *));
void insertion_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *));
void merge_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *));
void quick_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *));

#endif // SORT_H
