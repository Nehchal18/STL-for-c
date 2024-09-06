#include "../headers/utils.h"

void print_int_array(void *a, size_t n) {
    int *arr = (int *)a;
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_char_array(void *a, size_t n) {
    char *arr = (char *)a;
    for (size_t i = 0; i < n; ++i) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void print_float_array(void *a, size_t n) {
    float *arr = (float *)a;
    for (size_t i = 0; i < n; ++i) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void print_double_array(void *a, size_t n) {
    double *arr = (double *)a;
    for (size_t i = 0; i < n; ++i) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void print_string_array(void *a, size_t n) {
    char **arr = (char **)a;
    for (size_t i = 0; i < n; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}