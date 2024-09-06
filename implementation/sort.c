#include "../headers/sort.h"

static void swap(void *a, void *b, size_t elem_size) {
    void *temp = malloc(elem_size);
    if (temp == NULL) {
        // Handle memory allocation error
        return;
    }
    memcpy(temp, a, elem_size);
    memcpy(a, b, elem_size);
    memcpy(b, temp, elem_size);
    free(temp);
}

// Comparison function for int
int int_greater(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return (int_a > int_b) - (int_a < int_b);
}

int int_lesser(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return (int_a < int_b) - (int_a > int_b);
}

// Comparison function for char
int char_greater(const void *a, const void *b) {
    char char_a = *(const char *)a;
    char char_b = *(const char *)b;
    return (char_a > char_b) - (char_a < char_b);
}

int char_lesser(const void *a, const void *b) {
    char char_a = *(const char *)a;
    char char_b = *(const char *)b;
    return (char_a < char_b) - (char_a > char_b);
}

// Comparison function for float
int float_greater(const void *a, const void *b) {
    float float_a = *(const float *)a;
    float float_b = *(const float *)b;
    return (float_a > float_b) - (float_a < float_b);
}

int float_lesser(const void *a, const void *b) {
    float float_a = *(const float *)a;
    float float_b = *(const float *)b;
    return (float_a < float_b) - (float_a > float_b);
}

// Comparison function for double
int double_greater(const void *a, const void *b) {
    double double_a = *(const double *)a;
    double double_b = *(const double *)b;
    return (double_a > double_b) - (double_a < double_b);
}

int double_lesser(const void *a, const void *b) {
    double double_a = *(const double *)a;
    double double_b = *(const double *)b;
    return (double_a < double_b) - (double_a > double_b);
}

// Comparison function for strings (greater)
int string_greater(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Comparison function for strings (lesser)
int string_lesser(const void *a, const void *b) {
    return -strcmp(*(const char **)a, *(const char **)b);
}


// Bubble sort algorithm , Complexity O(n^2)
void bubble_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *)) {
    char *array = (char *)arr;
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            void *a = array + j * elem_size;
            void *b = array + (j + 1) * elem_size;
            if (compare(a, b) > 0) {
                swap(a, b, elem_size);
            }
        }
    }
}

// Selection sort algorithm, Complexity O(n^2)
void selection_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *)) {
    char *array = (char *)arr;
    for (size_t i = 0; i < n - 1; ++i) {
        void *min = array + i * elem_size;
        for (size_t j = i + 1; j < n; ++j) {
            void *current = array + j * elem_size;
            if (compare(current, min) < 0) {
                min = current;
            }
        }
        if (min != array + i * elem_size) {
            swap(array + i * elem_size, min, elem_size);
        }
    }
}

// Insertion sort algorithm, Complexity O(n^2)
void insertion_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *)) {
    char *array = (char *)arr;
    for (size_t i = 1; i < n; ++i) {
        void *key = array + i * elem_size;
        size_t j = i;
        while (j > 0 && compare(array + (j - 1) * elem_size, key) > 0) {
            memcpy(array + j * elem_size, array + (j - 1) * elem_size, elem_size);
            --j;
        }
        memcpy(array + j * elem_size, key, elem_size);
    }
}

// Merge sort algorithm, Complexity O(n log n)
static void merge(void *arr, size_t left, size_t mid, size_t right, size_t elem_size, int (*compare)(const void *, const void *)) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    void *L = malloc(n1 * elem_size);
    void *R = malloc(n2 * elem_size);

    if (L == NULL || R == NULL) {
        // Handle memory allocation error
        free(L);
        free(R);
        return;
    }

    memcpy(L, (char *)arr + left * elem_size, n1 * elem_size);
    memcpy(R, (char *)arr + (mid + 1) * elem_size, n2 * elem_size);

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare((char *)L + i * elem_size, (char *)R + j * elem_size) <= 0) {
            memcpy((char *)arr + k * elem_size, (char *)L + i * elem_size, elem_size);
            ++i;
        } else {
            memcpy((char *)arr + k * elem_size, (char *)R + j * elem_size, elem_size);
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        memcpy((char *)arr + k * elem_size, (char *)L + i * elem_size, elem_size);
        ++i;
        ++k;
    }

    while (j < n2) {
        memcpy((char *)arr + k * elem_size, (char *)R + j * elem_size, elem_size);
        ++j;
        ++k;
    }

    free(L);
    free(R);
}

// Merge sort (recursive)
static void merge_sort_recursive(void *arr, size_t left, size_t right, size_t elem_size, int (*compare)(const void *, const void *)) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        merge_sort_recursive(arr, left, mid, elem_size, compare);
        merge_sort_recursive(arr, mid + 1, right, elem_size, compare);
        merge(arr, left, mid, right, elem_size, compare);
    }
}

void merge_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *)) {
    merge_sort_recursive(arr, 0, n - 1, elem_size, compare);
}

// Quick sort algorithm, Complexity O(n log n)
static int partition(void *arr, int low, int high, size_t elem_size, int (*compare)(const void *, const void *)) {
    char *array = (char *)arr;
    void *pivot = array + high * elem_size;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (compare(array + j * elem_size, pivot) <= 0) {
            ++i;
            swap(array + i * elem_size, array + j * elem_size, elem_size);
        }
    }
    swap(array + (i + 1) * elem_size, pivot, elem_size);
    return i + 1;
}

// Quick sort (recursive)
static void quick_sort_recursive(void *arr, int low, int high, size_t elem_size, int (*compare)(const void *, const void *)) {
    if (low < high) {
        int pi = partition(arr, low, high, elem_size, compare);
        quick_sort_recursive(arr, low, pi - 1, elem_size, compare);
        quick_sort_recursive(arr, pi + 1, high, elem_size, compare);
    }
}

void quick_sort(void *arr, size_t n, size_t elem_size, int (*compare)(const void *, const void *)) {
    quick_sort_recursive(arr, 0, n - 1, elem_size, compare);
}