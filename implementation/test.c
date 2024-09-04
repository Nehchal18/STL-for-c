#include <stdio.h>
#include "vector.h"
#include "sort.h"
#include "utils.h"
#include "list.h"

int compare_int(const void *a, const void *b) {
    return *(int*)a == *(int*)b ? 0 : 1;
}

int compare_float(const void *a, const void *b) {
    return *(float*)a == *(float*)b ? 0 : 1;
}

int compare_string(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void print_int(void *data) {
    printf("%d ", *(int *)data);
}

void print_float(void *data) {
    printf("%.2f ", *(float *)data);
}

void print_string(void *data) {
    printf("%s ", *(char **)data);
}

void free_string(void *data) {
    free(*(char **)data);
}

int main() {

    // --------------------------------------- Test sorting algorithms ---------------------------------------
    /*
    int int_arr[] = {4, 2, 5, 1, 3};
    size_t int_n = sizeof(int_arr) / sizeof(int_arr[0]);
    bubble_sort(int_arr, int_n, sizeof(int), int_lesser);
    printf("Sorted int array (bubble_sort, int_lesser): ");
    print_int_array(int_arr, int_n);

    // Test char array
    char char_arr[] = {'d', 'a', 'c', 'b'};
    size_t char_n = sizeof(char_arr) / sizeof(char_arr[0]);
    selection_sort(char_arr, char_n, sizeof(char), char_lesser);
    printf("Sorted char array (selection_sort, char_lesser): ");
    print_char_array(char_arr, char_n);

    // Test float array
    float float_arr[] = {3.1f, 2.2f, 4.4f, 1.5f};
    size_t float_n = sizeof(float_arr) / sizeof(float_arr[0]);
    insertion_sort(float_arr, float_n, sizeof(float), float_lesser);
    printf("Sorted float array (insertion_sort, float_lesser): ");
    print_float_array(float_arr, float_n);

    // Test double array
    double double_arr[] = {2.3, 1.4, 3.5, 0.6};
    size_t double_n = sizeof(double_arr) / sizeof(double_arr[0]);
    merge_sort(double_arr, double_n, sizeof(double), double_lesser);
    printf("Sorted double array (merge_sort, double_lesser): ");
    print_double_array(double_arr, double_n);

    // Test string array
    char *string_arr[] = {"banana", "apple", "cherry", "date"};
    size_t string_n = sizeof(string_arr) / sizeof(string_arr[0]);
    quick_sort(string_arr, string_n, sizeof(char *), string_greater);
    printf("Sorted string array (quick_sort, string_lesser): ");
    print_string_array(string_arr, string_n);
    */

    // --------------------------------------- Test vector operations ---------------------------------------
    /*
    vector int_vector;
    vector_init(&int_vector, sizeof(int));
    int int_values[] = {10, 20, 30, 40, 50};
    for (size_t i = 0; i < sizeof(int_values) / sizeof(int_values[0]); ++i) {
        vector_push_back(&int_vector, &int_values[i]);
    }

    // Vector of floats
    vector float_vector;
    vector_init(&float_vector, sizeof(float));
    float float_values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (size_t i = 0; i < sizeof(float_values) / sizeof(float_values[0]); ++i) {
        vector_push_back(&float_vector, &float_values[i]);
    }

    // Vector of strings
    vector string_vector;
    vector_init(&string_vector, sizeof(char*));
    char *string_values[] = {"apple", "banana", "cherry", "date"};
    for (size_t i = 0; i < sizeof(string_values) / sizeof(string_values[0]); ++i) {
        vector_push_back(&string_vector, &string_values[i]);
    }

    // Test vector functions for integers
    printf("Integer vector after push_back: ");
    print_int_array(int_vector.data, int_vector.size);

    printf("Integer vector front element: %d\n", *(int*)vector_front(&int_vector));
    printf("Integer vector back element: %d\n", *(int*)vector_back(&int_vector));

    printf("Integer vector element at index 2: %d\n", *(int*)vector_get(&int_vector, 2));

    printf("Integer vector is empty: %s\n", vector_empty(&int_vector) ? "true" : "false");

    vector_reverse(&int_vector);
    printf("Integer vector after reverse: ");
    print_int_array(int_vector.data, int_vector.size);

    vector_pop_back(&int_vector);
    printf("Integer vector after pop_back: ");
    print_int_array(int_vector.data, int_vector.size);

    printf("Integer vector size: %zu\n", vector_size(&int_vector));
    printf("Integer vector capacity: %zu\n", vector_capacity(&int_vector));

    // Test find function
    int search_int = 20;
    size_t index = vector_find(&int_vector, &search_int, compare_int);
    if (index != (size_t)-1) {
        printf("Found %d at index %zu in the integer vector.\n", search_int, index);
    } else {
        printf("%d not found in the integer vector.\n", search_int);
    }

    vector_clear(&int_vector);
    printf("Integer vector after clear: ");
    print_int_array(int_vector.data, int_vector.size);

    // Free the integer vector
    vector_free(&int_vector);

    // Test vector functions for floats
    printf("\nFloat vector after push_back: ");
    print_float_array(float_vector.data, float_vector.size);

    printf("Float vector front element: %f\n", *(float*)vector_front(&float_vector));
    printf("Float vector back element: %f\n", *(float*)vector_back(&float_vector));

    printf("Float vector element at index 2: %f\n", *(float*)vector_get(&float_vector, 2));

    printf("Float vector is empty: %s\n", vector_empty(&float_vector) ? "true" : "false");

    vector_reverse(&float_vector);
    printf("Float vector after reverse: ");
    print_float_array(float_vector.data, float_vector.size);

    vector_pop_back(&float_vector);
    printf("Float vector after pop_back: ");
    print_float_array(float_vector.data, float_vector.size);

    printf("Float vector size: %zu\n", vector_size(&float_vector));
    printf("Float vector capacity: %zu\n", vector_capacity(&float_vector));

    // Test find function
    float search_float = 3.3;
    index = vector_find(&float_vector, &search_float, compare_float);
    if (index != (size_t)-1) {
        printf("Found %f at index %zu in the float vector.\n", search_float, index);
    } else {
        printf("%f not found in the float vector.\n", search_float);
    }

    vector_clear(&float_vector);
    printf("Float vector after clear: ");
    print_float_array(float_vector.data, float_vector.size);

    // Free the float vector
    vector_free(&float_vector);

    // Test vector functions for strings
    printf("\nString vector after push_back: ");
    print_string_array(string_vector.data, string_vector.size);

    printf("String vector front element: %s\n", *(char**)vector_front(&string_vector));
    printf("String vector back element: %s\n", *(char**)vector_back(&string_vector));

    printf("String vector element at index 2: %s\n", *(char**)vector_get(&string_vector, 2));

    printf("String vector is empty: %s\n", vector_empty(&string_vector) ? "true" : "false");

    vector_reverse(&string_vector);
    printf("String vector after reverse: ");
    print_string_array(string_vector.data, string_vector.size);

    vector_pop_back(&string_vector);
    printf("String vector after pop_back: ");
    print_string_array(string_vector.data, string_vector.size);

    printf("String vector size: %zu\n", vector_size(&string_vector));
    printf("String vector capacity: %zu\n", vector_capacity(&string_vector));

    // Test find function
    char *search_string = "banana";
    index = vector_find(&string_vector, &search_string, compare_string);
    if (index != (size_t)-1) {
        printf("Found %s at index %zu in the string vector.\n", search_string, index);
    } else {
        printf("%s not found in the string vector.\n", search_string);
    }

    vector_clear(&string_vector);
    printf("String vector after clear: ");
    print_string_array(string_vector.data, string_vector.size);

    // Free the string vector
    vector_free(&string_vector);
    */
    // --------------------------------------- Test List operations ---------------------------------------
    // /*
    SinglyLinkedList s_list_int;
    singly_list_init(&s_list_int, sizeof(int));

    int int_values[] = {10, 20, 30, 40, 50};
    for (size_t i = 0; i < sizeof(int_values) / sizeof(int_values[0]); i++) {
        singly_list_insert(&s_list_int, i, &int_values[i]);
    }

    printf("Singly Linked List (Integers): ");
    for (size_t i = 0; i < singly_list_size(&s_list_int); i++) {
        int *value = (int *)singly_list_get(&s_list_int, i);
        print_int(value);
    }
    printf("\n");

    singly_list_remove(&s_list_int, 2, NULL); // Remove an element at index 2
    printf("After Removing index 2 (Integers): ");
    for (size_t i = 0; i < singly_list_size(&s_list_int); i++) {
        int *value = (int *)singly_list_get(&s_list_int, i);
        print_int(value);
    }
    printf("\n");

    singly_list_destroy(&s_list_int, NULL);

    // Test Singly Linked List with floats
    SinglyLinkedList s_list_float;
    singly_list_init(&s_list_float, sizeof(float));

    float float_values[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    for (size_t i = 0; i < sizeof(float_values) / sizeof(float_values[0]); i++) {
        singly_list_insert(&s_list_float, i, &float_values[i]);
    }

    printf("Singly Linked List (Floats): ");
    for (size_t i = 0; i < singly_list_size(&s_list_float); i++) {
        float *value = (float *)singly_list_get(&s_list_float, i);
        print_float(value);
    }
    printf("\n");

    singly_list_remove(&s_list_float, 1, NULL); // Remove an element at index 1
    printf("After Removing index 1 (Floats): ");
    for (size_t i = 0; i < singly_list_size(&s_list_float); i++) {
        float *value = (float *)singly_list_get(&s_list_float, i);
        print_float(value);
    }
    printf("\n");

    singly_list_destroy(&s_list_float, NULL);

    // Test Singly Linked List with strings
    SinglyLinkedList s_list_str;
    singly_list_init(&s_list_str, sizeof(char *));

    char *str_values[] = {"apple", "banana", "cherry", "date", "elderberry"};
    for (size_t i = 0; i < sizeof(str_values) / sizeof(str_values[0]); i++) {
        char *str_copy = strdup(str_values[i]);
        singly_list_insert(&s_list_str, i, &str_copy);
    }

    printf("Singly Linked List (Strings): ");
    for (size_t i = 0; i < singly_list_size(&s_list_str); i++) {
        char **value = (char **)singly_list_get(&s_list_str, i);
        print_string(value);
    }
    printf("\n");

    singly_list_remove(&s_list_str, 3, free_string); // Remove an element at index 3
    printf("After Removing index 3 (Strings): ");
    for (size_t i = 0; i < singly_list_size(&s_list_str); i++) {
        char **value = (char **)singly_list_get(&s_list_str, i);
        print_string(value);
    }
    printf("\n");

    singly_list_destroy(&s_list_str, free_string);

    // Test Doubly Linked List with integers
    DoublyLinkedList d_list_int;
    doubly_list_init(&d_list_int, sizeof(int));

    for (size_t i = 0; i < sizeof(int_values) / sizeof(int_values[0]); i++) {
        doubly_list_insert(&d_list_int, i, &int_values[i]);
    }

    printf("Doubly Linked List (Integers): ");
    for (size_t i = 0; i < doubly_list_size(&d_list_int); i++) {
        int *value = (int *)doubly_list_get(&d_list_int, i);
        print_int(value);
    }
    printf("\n");

    doubly_list_remove(&d_list_int, 0, NULL); // Remove an element at index 0
    printf("After Removing index 0 (Integers): ");
    for (size_t i = 0; i < doubly_list_size(&d_list_int); i++) {
        int *value = (int *)doubly_list_get(&d_list_int, i);
        print_int(value);
    }
    printf("\n");

    doubly_list_destroy(&d_list_int, NULL);

    // Test Doubly Linked List with floats
    DoublyLinkedList d_list_float;
    doubly_list_init(&d_list_float, sizeof(float));

    for (size_t i = 0; i < sizeof(float_values) / sizeof(float_values[0]); i++) {
        doubly_list_insert(&d_list_float, i, &float_values[i]);
    }

    printf("Doubly Linked List (Floats): ");
    for (size_t i = 0; i < doubly_list_size(&d_list_float); i++) {
        float *value = (float *)doubly_list_get(&d_list_float, i);
        print_float(value);
    }
    printf("\n");

    doubly_list_remove(&d_list_float, 4, NULL); // Remove an element at index 4
    printf("After Removing index 4 (Floats): ");
    for (size_t i = 0; i < doubly_list_size(&d_list_float); i++) {
        float *value = (float *)doubly_list_get(&d_list_float, i);
        print_float(value);
    }
    printf("\n");

    doubly_list_destroy(&d_list_float, NULL);

    // Test Doubly Linked List with strings
    DoublyLinkedList d_list_str;
    doubly_list_init(&d_list_str, sizeof(char *));

    for (size_t i = 0; i < sizeof(str_values) / sizeof(str_values[0]); i++) {
        char *str_copy = strdup(str_values[i]);
        doubly_list_insert(&d_list_str, i, &str_copy);
    }

    printf("Doubly Linked List (Strings): ");
    for (size_t i = 0; i < doubly_list_size(&d_list_str); i++) {
        char **value = (char **)doubly_list_get(&d_list_str, i);
        print_string(value);
    }
    printf("\n");

    doubly_list_remove(&d_list_str, 2, free_string); // Remove an element at index 2
    printf("After Removing index 2 (Strings): ");
    for (size_t i = 0; i < doubly_list_size(&d_list_str); i++) {
        char **value = (char **)doubly_list_get(&d_list_str, i);
        print_string(value);
    }
    printf("\n");

    doubly_list_destroy(&d_list_str, free_string);
    // */

    return 0;
}