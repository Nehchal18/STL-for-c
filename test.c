#include "./headers/everything.h"

int int_compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int float_compare(const void* a, const void* b) {
    if (*(float*)a < *(float*)b) return -1;
    else if (*(float*)a > *(float*)b) return 1;
    return 0;
}

int string_compare(const void* a, const void* b) {
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

void destroy_string(void *data) {
    // if(!data) return;
    free(data);  // Directly free the void* which points to the string
}

void print_test_result(const char *test_name, bool passed) {
    printf("%s: %s\n", test_name, passed ? "PASSED" : "FAILED");
}

int main() {

    // --------------------------------------- Test sorting algorithms ---------------------------------------
    
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

    // --------------------------------------- Test vector operations ---------------------------------------
    
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
    size_t index = vector_find(&int_vector, &search_int, int_compare);
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
    index = vector_find(&float_vector, &search_float, float_compare);
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
    index = vector_find(&string_vector, &search_string, string_compare);
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

    // --------------------------------------- Test List operations -----------------------------------------
    
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

    singly_list_free(&s_list_int, NULL);

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

    singly_list_free(&s_list_float, NULL);

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

    singly_list_free(&s_list_str, free_string);

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

    doubly_list_free(&d_list_int, NULL);

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

    doubly_list_free(&d_list_float, NULL);

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

    doubly_list_free(&d_list_str, free_string);

    // --------------------------------------- Test Stack operations -----------------------------------------
    
    // Test stack with integers
    Stack int_stack;
    stack_init(&int_stack, sizeof(int));
    int a = 10, b = 20, c = 30;
    stack_push(&int_stack, &a);
    stack_push(&int_stack, &b);
    stack_push(&int_stack, &c);
    printf("Integer stack top: %d\n", *(int *)stack_top(&int_stack));
    stack_pop(&int_stack, NULL);
    printf("Integer stack top after pop: %d\n", *(int *)stack_top(&int_stack));
    printf("Integer stack size: %zu\n", stack_size(&int_stack));
    stack_free(&int_stack, NULL);

    // Test stack with floating-point numbers
    Stack float_stack;
    stack_init(&float_stack, sizeof(float));
    float x = 1.1, y = 2.2, z = 3.3;
    stack_push(&float_stack, &x);
    stack_push(&float_stack, &y);
    stack_push(&float_stack, &z);
    printf("Float stack top: %.2f\n", *(float *)stack_top(&float_stack));
    stack_pop(&float_stack, NULL);
    printf("Float stack top after pop: %.2f\n", *(float *)stack_top(&float_stack));
    printf("Float stack size: %zu\n", stack_size(&float_stack));
    stack_free(&float_stack, NULL);

    // Test stack with strings
    Stack string_stack;
    stack_init(&string_stack, sizeof(char *));
    char *str1 = strdup("hello");
    char *str2 = strdup("world");
    char *str3 = strdup("!");
    stack_push(&string_stack, &str1);
    stack_push(&string_stack, &str2);
    stack_push(&string_stack, &str3);
    printf("String stack top: %s\n", *(char **)stack_top(&string_stack));
    stack_pop(&string_stack, free_string);
    printf("String stack top after pop: %s\n", *(char **)stack_top(&string_stack));
    printf("String stack size: %zu\n", stack_size(&string_stack));
    stack_free(&string_stack, free_string);

    // --------------------------------------- Test Queue operations -----------------------------------------
    
    // // Testing queue with integers
    // Queue queue;
    // queue_init(&queue, sizeof(int));
    // int a = 10, b = 20, c = 30;
    // printf("\n--- Testing Integer Queue ---\n");
    // queue_enqueue(&queue, &a);
    // queue_enqueue(&queue, &b);
    // queue_enqueue(&queue, &c);
    // printf("Front of queue: %d\n", *(int *)queue_front(&queue));
    // queue_dequeue(&queue, NULL);
    // printf("Front after dequeue: %d\n", *(int *)queue_front(&queue));
    // printf("Queue size: %zu\n", queue_size(&queue));
    // queue_free(&queue, NULL);
    
    // // Testing queue with floats
    // Queue queue;
    // queue_init(&queue, sizeof(float));
    // float a = 1.1, b = 2.2, c = 3.3;
    // printf("\n--- Testing Float Queue ---\n");
    // queue_enqueue(&queue, &a);
    // queue_enqueue(&queue, &b);
    // queue_enqueue(&queue, &c);
    // printf("Front of queue: %.1f\n", *(float *)queue_front(&queue));
    // queue_dequeue(&queue, NULL);
    // printf("Front after dequeue: %.1f\n", *(float *)queue_front(&queue));
    // printf("Queue size: %zu\n", queue_size(&queue));
    // queue_free(&queue, NULL);
    
    // // Testing queue with strings
    // Queue queue;
    // queue_init(&queue, sizeof(char *));
    // char *a = strdup("Apple");
    // char *b = strdup("Banana");
    // char *c = strdup("Cherry");
    // printf("\n--- Testing String Queue ---\n");
    // queue_enqueue(&queue, &a);
    // queue_enqueue(&queue, &b);
    // queue_enqueue(&queue, &c);
    // printf("Front of queue: %s\n", *(char **)queue_front(&queue));
    // queue_dequeue(&queue, free_string);
    // printf("Front after dequeue: %s\n", *(char **)queue_front(&queue));
    // printf("Queue size: %zu\n", queue_size(&queue));
    // queue_free(&queue, free_string);
    
    // // Testing deque with integers
    // Deque deque;
    // deque_init(&deque, sizeof(int));
    // int a = 10, b = 20, c = 30;
    // printf("\n--- Testing Integer Deque ---\n");
    // deque_push_front(&deque, &a);
    // deque_push_back(&deque, &b);
    // deque_push_back(&deque, &c);
    // printf("Front of deque: %d\n", *(int *)deque_front(&deque));
    // printf("Back of deque: %d\n", *(int *)deque_back(&deque));
    // deque_pop_front(&deque, NULL);
    // printf("Front after pop: %d\n", *(int *)deque_front(&deque));
    // printf("Deque size: %zu\n", deque_size(&deque));
    // deque_free(&deque, NULL);
    
    // // Testing deque with floats
    // Deque deque;
    // deque_init(&deque, sizeof(float));
    // float a = 1.1, b = 2.2, c = 3.3;
    // printf("\n--- Testing Float Deque ---\n");
    // deque_push_front(&deque, &a);
    // deque_push_back(&deque, &b);
    // deque_push_back(&deque, &c);
    // printf("Front of deque: %.1f\n", *(float *)deque_front(&deque));
    // printf("Back of deque: %.1f\n", *(float *)deque_back(&deque));
    // deque_pop_front(&deque, NULL);
    // printf("Front after pop: %.1f\n", *(float *)deque_front(&deque));
    // printf("Deque size: %zu\n", deque_size(&deque));
    // deque_free(&deque, NULL);
    
    // // Testing deque with strings
    // Deque deque;
    // deque_init(&deque, sizeof(char *));
    // char *a = strdup("First");
    // char *b = strdup("Second");
    // char *c = strdup("Third");
    // printf("\n--- Testing String Deque ---\n");
    // deque_push_back(&deque, &a);
    // deque_push_front(&deque, &b);
    // deque_push_back(&deque, &c);
    // printf("Front of deque: %s\n", *(char **)deque_front(&deque));
    // printf("Back of deque: %s\n", *(char **)deque_back(&deque));
    // deque_pop_front(&deque, free_string);
    // printf("Front after pop: %s\n", *(char **)deque_front(&deque));
    // printf("Deque size: %zu\n", deque_size(&deque));
    // deque_free(&deque, free_string);

    // ----------------------------------- Test Priority Queue operations ------------------------------------
    
    // Test priority queue with integers
    priority_queue pq;
    priority_queue_init(&pq, sizeof(int), int_lesser);
    int a = 10, b = 20, c = 15;
    printf("\n--- Testing Integer Priority Queue ---\n");
    priority_queue_push(&pq, &a);
    priority_queue_push(&pq, &b);
    priority_queue_push(&pq, &c);
    printf("Top of priority queue: %d\n", *(int*)priority_queue_top(&pq));
    priority_queue_pop(&pq);
    printf("Top after pop: %d\n", *(int*)priority_queue_top(&pq));
    printf("Priority queue is empty: %s\n", priority_queue_empty(&pq) ? "true" : "false");
    priority_queue_free(&pq);

    // Test priority queue with floats
    priority_queue pq;
    priority_queue_init(&pq, sizeof(float), float_greater);
    float a = 1.1, b = 2.2, c = 1.5;
    printf("\n--- Testing Float Priority Queue ---\n");
    priority_queue_push(&pq, &a);
    priority_queue_push(&pq, &b);
    priority_queue_push(&pq, &c);
    printf("Top of priority queue: %.1f\n", *(float*)priority_queue_top(&pq));
    priority_queue_pop(&pq);
    printf("Top after pop: %.1f\n", *(float*)priority_queue_top(&pq));
    printf("Priority queue is empty: %s\n", priority_queue_empty(&pq) ? "true" : "false");
    priority_queue_free(&pq);

    // Test priority queue with strings
    priority_queue pq;
    priority_queue_init(&pq, sizeof(char*), string_lesser);
    char *a = strdup("Banana");
    char *b = strdup("Apple");
    char *c = strdup("Cherry");
    printf("\n--- Testing String Priority Queue ---\n");
    priority_queue_push(&pq, &a);
    priority_queue_push(&pq, &b);
    priority_queue_push(&pq, &c);
    printf("Top of priority queue: %s\n", *(char**)priority_queue_top(&pq));
    priority_queue_pop(&pq);
    printf("Top after pop: %s\n", *(char**)priority_queue_top(&pq));
    printf("Priority queue is empty: %s\n", priority_queue_empty(&pq) ? "true" : "false");
    priority_queue_free(&pq);
    free_string(&a);
    free_string(&b);
    free_string(&c);

    // ---------------------------------------- Test Set operations ------------------------------------------
    
    // Test set with integers
    Set* int_set = set_create(int_compare, NULL, sizeof(int));
    int nums[] = {5, 3, 7, 1, 4, 9};
    for (int i = 0; i < 6; ++i) {
        set_insert(int_set, &nums[i]);
    }
    int val = 3;
    if (set_contains(int_set, &val)) {
        printf("%d is in the set.\n", val);
    }
    set_remove(int_set, &val);
    if (!set_contains(int_set, &val)) {
        printf("%d has been removed from the set.\n", val);
    }
    if (!set_contains(int_set, &val)) {
        printf("%d is not in the set.\n", val);
    }
    set_destroy(int_set);

    // Test set with floats
    Set* float_set = set_create(float_compare, NULL, sizeof(float));
    float nums[] = {5.5, 3.1, 7.2, 1.9, 4.4, 9.8};
    for (int i = 0; i < 6; ++i) {
        set_insert(float_set, &nums[i]);
    }
    float val = 3.1;
    if (set_contains(float_set, &val)) {
        printf("%.1f is in the set.\n", val);
    }
    set_remove(float_set, &val);
    if (!set_contains(float_set, &val)) {
        printf("%.1f has been removed from the set.\n", val);
    }
    if (!set_contains(float_set, &val)) {
        printf("%.1f is in not the set.\n", val);
    }
    set_destroy(float_set);

    // Test set with strings
    Set* string_set = set_create(string_compare, free_string, sizeof(char*));
    char* words[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    for (int i = 0; i < 6; ++i) {
        char* word_copy = strdup(words[i]); 
        set_insert(string_set, &word_copy);
    }
    char* search_word = strdup("banana");
    if (set_contains(string_set, &search_word)) {
        printf("%s is in the set.\n", search_word);
    }
    set_remove(string_set, &search_word);
    if (!set_contains(string_set, &search_word)) {
        printf("%s has been removed from the set.\n", search_word);
    }
    free(search_word);

    // ----------------------------------------- Test Map operations -----------------------------------------
    
    // Test with integers
    HashMap *int_map = hashmap_create(10, sizeof(int), sizeof(int), int_hash, int_compare);
    int key1 = 5, value1 = 100;
    int key2 = 10, value2 = 200;
    int key3 = 15, value3 = 300;
    hashmap_insert(int_map, &key1, &value1);
    hashmap_insert(int_map, &key2, &value2);
    hashmap_insert(int_map, &key3, &value3);
    int *result1 = (int *)hashmap_get(int_map, &key1);
    int *result2 = (int *)hashmap_get(int_map, &key2);
    int *result3 = (int *)hashmap_get(int_map, &key3);
    print_test_result("Test Get Key1", result1 && *result1 == value1);
    print_test_result("Test Get Key2", result2 && *result2 == value2);
    print_test_result("Test Get Key3", result3 && *result3 == value3);
    hashmap_destroy(int_map);

    Test with strings
    HashMap *str_map = hashmap_create(10, sizeof(char *), sizeof(int), string_hash, string_compare);
    char *key1 = "apple";
    char *key2 = "banana";
    char *key3 = "cherry";
    int value1 = 100;
    int value2 = 200;
    int value3 = 300;
    hashmap_insert(str_map, &key1, &value1);
    hashmap_insert(str_map, &key2, &value2);
    hashmap_insert(str_map, &key3, &value3);
    int *result1 = (int *)hashmap_get(str_map, &key1);
    int *result2 = (int *)hashmap_get(str_map, &key2);
    int *result3 = (int *)hashmap_get(str_map, &key3);
    print_test_result("Test Get Key1", result1 && *result1 == value1);
    print_test_result("Test Get Key2", result2 && *result2 == value2);
    print_test_result("Test Get Key3", result3 && *result3 == value3);
    hashmap_destroy(str_map);

    // Test with floats
    HashMap *float_map = hashmap_create(10, sizeof(float), sizeof(int), float_hash, float_compare);
    float key1 = 3.14, key2 = 2.71, key3 = 1.41;
    int value1 = 100, value2 = 200, value3 = 300;
    hashmap_insert(float_map, &key1, &value1);
    hashmap_insert(float_map, &key2, &value2);
    hashmap_insert(float_map, &key3, &value3);
    int *result1 = (int *)hashmap_get(float_map, &key1);
    int *result2 = (int *)hashmap_get(float_map, &key2);
    int *result3 = (int *)hashmap_get(float_map, &key3);
    print_test_result("Test Get Key1", result1 && *result1 == value1);
    print_test_result("Test Get Key2", result2 && *result2 == value2);
    print_test_result("Test Get Key3", result3 && *result3 == value3);
    hashmap_destroy(float_map);
    return 0;
}