# C-STL: A Simple STL-like Library for C

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Utility Functions](#utility-functions)
  - [Sorting Algorithms](#sorting-algorithms)
  - [Vector](#vector)
  - [List](#list)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Priority Queue](#priority-queue)
  - [Set](#set)
  - [Map](#map)
- [License](#license)
- [Contributing](#contributing)

## Overview

C-STL is a simple implementation of some of the most commonly used data structures from the C++ Standard Template Library (STL) in C. This project aims to provide a familiar interface for developers who want to use dynamic data structures in C, without the overhead of manually managing memory and other complexities.
<br>
The library will include implementations of dynamic arrays (vectors), linked lists, stacks, queues, and maps (associative arrays). While these implementations do not have the full range of features found in the C++ STL, they provide a solid foundation for building more complex applications.

## Features

- **Dynamic Arrays (Vectors)**: Efficiently manage collections of elements with automatic resizing.
- **Linked Lists**: Implement singly and doubly linked lists for flexible data storage.
- **Stacks**: Use LIFO (Last In, First Out) data structure for managing elements.
- **Queues**: Implement FIFO (First In, First Out) data structure for orderly processing.
- **Sorting Algorithms**: Include various sorting algorithms like quicksort, mergesort, and bubblesort.
- **Searching Algorithms**: Implement searching techniques such as binary search and linear search.
- **Priority Queues**: Manage elements with priority levels using heaps.
- **Hash Tables**: Efficiently store and retrieve data using hash functions.
- **Tree Data Structures**: Implement binary trees for hierarchical data storage.
- **Utility Functions**: Include common utility functions for data manipulation and analysis.

## Installation

To install and use the C-STL library, follow these steps:

1. **Clone the Repository**:

   ```sh
   git clone https://github.com/nehchal18/stl-for-c.git
   cd stl-for-c
   ```

2. **Use the Library**:
   - Include the necessary header files in your C program.
   - Compile the program with the library source files linking to the static library file.
   - Run the compiled executable to see the output.

3. **Compile and Run Example Programs**:

   ```sh
    ./build.sh
    gcc -o output {c_file}.c -L. lib_mylib.a
    ./output
    ```

## Usage

### Utility Functions

The utility functions in C-STL provide common operations for working with data, such as swapping elements, generating random numbers, and calculating the maximum and minimum values, printing array.

**Note :** This header is still under development and will be updated soon.

```c

#include "utility.h"

int main() {
    // Integer array
    int int_arr[] = {1, 2, 3, 4, 5};
    printf("Integer Array: ");
    print_int_array(int_arr, 5);

    // Float array
    float float_arr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    printf("Float Array: ");
    print_float_array(float_arr, 5);

    // String array
    char *str_arr[] = {"Hello", "World", "From", "C"};
    printf("String Array: ");
    print_string_array(str_arr, 4);

    return 0;

}
```

### Sorting Algorithms

C-STL provides various sorting algorithms for arrays of integers, floats, and strings. These algorithms include quicksort, mergesort, bubblesort, and insertion sort.

```c
#include "sort.h" 

int main() {
    // Example usage of sorting functions

    // Integer array
    int int_arr[] = {5, 3, 1, 4, 2};
    size_t n = sizeof(int_arr) / sizeof(int_arr[0]);

    printf("Integer Array - Before Sorting: ");
    print_int_array(int_arr, n);

    bubble_sort(int_arr, n, sizeof(int), int_lesser);
    printf("Integer Array - After Bubble Sort: ");
    print_int_array(int_arr, n);

    // Character array
    char char_arr[] = {'e', 'd', 'b', 'a', 'c'};
    n = sizeof(char_arr) / sizeof(char_arr[0]);

    printf("Character Array - Before Sorting: ");
    print_char_array(char_arr, n);

    insertion_sort(char_arr, n, sizeof(char), char_lesser);
    printf("Character Array - After Insertion Sort: ");
    print_char_array(char_arr, n);

    // Float array
    float float_arr[] = {5.5f, 3.3f, 1.1f, 4.4f, 2.2f};
    n = sizeof(float_arr) / sizeof(float_arr[0]);

    printf("Float Array - Before Sorting: ");
    print_float_array(float_arr, n);

    merge_sort(float_arr, n, sizeof(float), float_lesser);
    printf("Float Array - After Merge Sort: ");
    print_float_array(float_arr, n);

    // Double array
    double double_arr[] = {5.55, 3.33, 1.11, 4.44, 2.22};
    n = sizeof(double_arr) / sizeof(double_arr[0]);

    printf("Double Array - Before Sorting: ");
    print_double_array(double_arr, n);

    quick_sort(double_arr, n, sizeof(double), double_lesser);
    printf("Double Array - After Quick Sort: ");
    print_double_array(double_arr, n);

    // String array
    char *str_arr[] = {"banana", "apple", "cherry", "date"};
    n = sizeof(str_arr) / sizeof(str_arr[0]);

    printf("String Array - Before Sorting: ");
    print_string_array(str_arr, n);

    selection_sort(str_arr, n, sizeof(char*), string_lesser);
    printf("String Array - After Selection Sort: ");
    print_string_array(str_arr, n);

    return 0;
}
```

// Comparison functions for all data types 

### Vector

Vectors in C-STL are dynamic arrays that automatically resize as elements are added or removed. They provide an efficient way to manage collections of data with random access.

```c
#include "vector.h"

// Comparison function for integers
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Initialize the vector with size for integer elements.
    vector vec;
    vector_init(&vec, sizeof(int));

    // Add elements to the vector.
    int value = 10;
    vector_push_back(&vec, &value);
    value = 20;
    vector_push_back(&vec, &value);

    // Access the first element of the vector.
    int front = *(int*)vector_front(&vec);

    // Remove the last element from the vector.
    vector_pop_back(&vec);

    // Access the last element of the vector.
    int back = *(int*)vector_back(&vec);

    // Access an element at a specific index (index 0 in this case).
    int element = *(int*)vector_get(&vec, 0);

    // Reverse the order of elements in the vector.
    vector_reverse(&vec);

    // Get the number of elements in the vector.
    size_t size = vector_size(&vec);

    // Get the capacity of the vector.
    size_t capacity = vector_capacity(&vec);

    // Check if the vector is empty.
    bool is_empty = vector_empty(&vec);

    // Find the index of an element (value 20). Returns -1 if not found.
    size_t index = vector_find(&vec, &value, compare_int);

    // Clear all elements from the vector, but retain its capacity.
    vector_clear(&vec);

    // Free the memory allocated for the vector.
    vector_free(&vec);

    return 0;
}
```

### List

C-STL's linked list implementation supports both singly and doubly linked lists, allowing for flexible insertion and deletion of elements.

```c
#include "list.h"

// Free function for integer data
void free_int(void *data) {
    // In this case, no action is needed since we are not allocating memory for integers.
    // This function is provided to match the function signature expected by the list functions.
}

int main() {
    // Initialize singly linked list with integer elements
    SinglyLinkedList s_list;
    singly_list_init(&s_list, sizeof(int));

    // Add elements to the singly linked list
    int value = 10;
    singly_list_insert(&s_list, 0, &value);
    value = 20;
    singly_list_insert(&s_list, 1, &value);

    // Get an element at a specific index (index 0 in this case)
    int *element = (int*)singly_list_get(&s_list, 0);
    printf("Singly Linked List - Element at index 0: %d\n", *element);

    // Remove an element from the singly linked list
    singly_list_remove(&s_list, 1, free_int);

    // Check if the singly linked list is empty
    bool is_empty = singly_list_empty(&s_list);
    printf("Singly Linked List - Is Empty: %s\n", is_empty ? "Yes" : "No");

    // Get the size of the singly linked list
    size_t size = singly_list_size(&s_list);
    printf("Singly Linked List - Size: %zu\n", size);

    // Clear all elements from the singly linked list
    singly_list_clear(&s_list, free_int);

    // Free the singly linked list
    singly_list_free(&s_list, free_int);

    // Initialize doubly linked list with integer elements
    DoublyLinkedList d_list;
    doubly_list_init(&d_list, sizeof(int));

    // Add elements to the doubly linked list
    value = 30;
    doubly_list_insert(&d_list, 0, &value);
    value = 40;
    doubly_list_insert(&d_list, 1, &value);

    // Get an element at a specific index (index 0 in this case)
    element = (int*)doubly_list_get(&d_list, 0);
    printf("Doubly Linked List - Element at index 0: %d\n", *element);

    // Remove an element from the doubly linked list
    doubly_list_remove(&d_list, 1, free_int);

    // Check if the doubly linked list is empty
    is_empty = doubly_list_empty(&d_list);
    printf("Doubly Linked List - Is Empty: %s\n", is_empty ? "Yes" : "No");

    // Get the size of the doubly linked list
    size = doubly_list_size(&d_list);
    printf("Doubly Linked List - Size: %zu\n", size);

    // Clear all elements from the doubly linked list
    doubly_list_clear(&d_list, free_int);

    // Free the doubly linked list
    doubly_list_free(&d_list, free_int);
    return 0;
}
```

### Stack

Stacks in C-STL provide a LIFO (Last In, First Out) structure, useful for scenarios like function call management and expression evaluation.

```c
#include "stack.h"

// Free function for integer data
void free_int(void *data) {
    // In this case, no action is needed since we are not allocating memory for integers.
    // This function is provided to match the function signature expected by the stack functions.
}

int main() {
    Stack stack;
    stack_init(&stack, sizeof(int));

    // Push elements onto the stack
    int value = 10;
    stack_push(&stack, &value);
    value = 20;
    stack_push(&stack, &value);

    // Access the top element of the stack
    int *top = (int*)stack_top(&stack);
    printf("Stack - Top Element: %d\n", *top);

    // Pop an element from the stack
    stack_pop(&stack, free_int);

    // Check if the stack is empty
    bool is_empty = stack_empty(&stack);
    printf("Stack - Is Empty: %s\n", is_empty ? "Yes" : "No");

    // Get the size of the stack
    size_t size = stack_size(&stack);
    printf("Stack - Size: %zu\n", size);

    // Free the stack
    stack_free(&stack, free_int);
    return 0;
}
```

### Queue

Queues in C-STL implement a FIFO (First In, First Out) data structure, suitable for tasks like task scheduling and breadth-first search.

```c
#include "queue.h"

// Free function for integer data
void free_int(void *data) {
    // In this case, no action is needed since we are not allocating memory for integers.
    // This function is provided to match the function signature expected by the queue and deque functions.
}

int main() {
    // Initialize the queue with integer elements
    Queue queue;
    queue_init(&queue, sizeof(int));

    // Enqueue elements into the queue
    int value = 10;
    queue_enqueue(&queue, &value);
    value = 20;
    queue_enqueue(&queue, &value);

    // Access the front element of the queue
    int *front = (int*)queue_front(&queue);
    printf("Queue - Front Element: %d\n", *front);

    // Dequeue an element from the queue
    queue_dequeue(&queue, free_int);

    // Check if the queue is empty
    bool is_empty = queue_empty(&queue);
    printf("Queue - Is Empty: %s\n", is_empty ? "Yes" : "No");

    // Get the size of the queue
    size_t size = queue_size(&queue);
    printf("Queue - Size: %zu\n", size);

    // Free the queue
    queue_free(&queue, free_int);

    // Initialize the deque with integer elements
    Deque deque;
    deque_init(&deque, sizeof(int));

    // Push elements to the front and back of the deque
    value = 30;
    deque_push_front(&deque, &value);
    value = 40;
    deque_push_back(&deque, &value);

    // Access the front and back elements of the deque
    int *front_elem = (int*)deque_front(&deque);
    int *back_elem = (int*)deque_back(&deque);
    printf("Deque - Front Element: %d\n", *front_elem);
    printf("Deque - Back Element: %d\n", *back_elem);

    // Pop elements from the front and back of the deque
    deque_pop_front(&deque, free_int);
    deque_pop_back(&deque, free_int);

    // Check if the deque is empty
    is_empty = deque_empty(&deque);
    printf("Deque - Is Empty: %s\n", is_empty ? "Yes" : "No");

    // Get the size of the deque
    size = deque_size(&deque);
    printf("Deque - Size: %zu\n", size);

    // Free the deque
    deque_free(&deque, free_int);
    return 0;
}
```

### Priority Queue

Priority queues in C-STL allow you to manage elements based on their priority levels, using a heap data structure for efficient operations.

```c
#include "priority_queue.h"

// Your can use Comparison function for all datatypes that are present in sort.h for min-heaps

int main() {
    // Initialize the priority queue with integer elements and a comparison function
    priority_queue pq;
    priority_queue_init(&pq, sizeof(int), compare_int);

    // Push elements into the priority queue
    int value = 10;
    priority_queue_push(&pq, &value);
    value = 20;
    priority_queue_push(&pq, &value);
    value = 15;
    priority_queue_push(&pq, &value);

    // Access the top element of the priority queue (highest priority)
    int *top = (int*)priority_queue_top(&pq);
    printf("Priority Queue - Top Element: %d\n", *top);

    // Pop the top element from the priority queue
    priority_queue_pop(&pq);

    // Access the new top element of the priority queue
    top = (int*)priority_queue_top(&pq);
    printf("Priority Queue - New Top Element: %d\n", *top);

    // Check if the priority queue is empty
    bool is_empty = priority_queue_empty(&pq);
    printf("Priority Queue - Is Empty: %s\n", is_empty ? "Yes" : "No");

    // Free the priority queue
    priority_queue_free(&pq);

    return 0;
}
```

### Set

Sets in C-STL allow you to store unique elements .

**Note :** This header is still under development and will be updated soon.

```c
#include "set.h"

// Comparison function for integers
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Destroy function for integers
void destroy_int(void *data) {
    // No special action needed for int
}

int main() {
    // Create a set of integers
    Set *set = set_create(compare_int, destroy_int, sizeof(int));

    int values[] = {10, 20, 30, 40, 50};
    size_t num_values = sizeof(values) / sizeof(values[0]);

    // Insert values into the set
    for (size_t i = 0; i < num_values; ++i) {
        set_insert(set, &values[i]);
    }

    // Check if certain values are in the set
    int value_to_check = 30;
    if (set_contains(set, &value_to_check)) {
        printf("%d is in the set.\n", value_to_check);
    } else {
        printf("%d is not in the set.\n", value_to_check);
    }

    // Remove a value from the set
    int value_to_remove = 20;
    set_remove(set, &value_to_remove);

    // Check if the removed value is still in the set
    if (set_contains(set, &value_to_remove)) {
        printf("%d is in the set.\n", value_to_remove);
    } else {
        printf("%d is not in the set.\n", value_to_remove);
    }

    // Get the size of the set
    size_t size = set_size(set);
    printf("The set size is %zu.\n", size);

    // Destroy the set
    set_destroy(set);

    return 0;
}
```

### Map

Maps (associative arrays) in C-STL allow you to store and retrieve key-value pairs efficiently.

**Note :** This header is still under development and will be updated soon.

```c
#include "map.h"

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    // Create a hashmap for integers
    HashMap *int_map = hashmap_create(10, sizeof(int), sizeof(int), int_hash, compare_ints);

    // Insert key-value pairs
    int key1 = 1, value1 = 100;
    hashmap_insert(int_map, &key1, &value1);
    
    int key2 = 2, value2 = 200;
    hashmap_insert(int_map, &key2, &value2);

    // Retrieve a value by key
    int *retrieved_value = (int *)hashmap_get(int_map, &key1);
    if (retrieved_value) {
        printf("Value for key %d: %d\n", key1, *retrieved_value);
    }

    // Check if a key exists in the map
    if (hashmap_contains(int_map, &key2)) {
        printf("Key %d is present in the map.\n", key2);
    }

    // Remove a key-value pair
    hashmap_remove(int_map, &key1);

    // Clear all key-value pairs
    hashmap_clear(int_map);

    // Destroy the hashmap and free memory
    hashmap_destroy(int_map);

    // Create a hashmap for strings
    HashMap *string_map = hashmap_create(10, sizeof(char *), sizeof(int), string_hash, compare_strings);

    // Insert key-value pairs
    const char *str_key1 = "hello";
    int str_value1 = 42;
    hashmap_insert(string_map, &str_key1, &str_value1);

    // Retrieve a value by string key
    retrieved_value = (int *)hashmap_get(string_map, &str_key1);
    if (retrieved_value) {
        printf("Value for key '%s': %d\n", str_key1, *retrieved_value);
    }

    // Destroy the string map
    hashmap_destroy(string_map);

    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

We welcome contributions from the community to help improve and expand the C-STL library. Here are some ways you can contribute:

1. **Reporting Bugs**: If you find a bug or any issue, please report it by opening an issue on the GitHub repository. Provide as much detail as possible, including steps to reproduce the issue, and any relevant screenshots or error messages.

2. **Submitting Pull Requests**: If you'd like to contribute code, you can do so by forking the repository, creating a new branch, and submitting a pull request. Please make sure to follow the project's coding guidelines and write clear, concise commit messages. Additionally, include detailed comments in the code to help others understand your changes.

3. **Writing Documentation**: Good documentation is key to the success of any open-source project. You can help by improving the existing documentation, writing tutorials, or adding examples to the `README.md` file. If you're familiar with Doxygen, consider adding comments to the code for auto-generating documentation.

4. **Enhancing Features**: You can contribute by adding new features to the library, such as additional data structures, algorithms, or utility functions. Before starting work on a new feature, it's a good idea to discuss it with the project maintainers by opening an issue or starting a discussion thread.

5. **Optimizing Code**: Performance is critical in data structure libraries. If you have ideas for optimizing the existing code, whether through algorithmic improvements or more efficient memory management, your contributions would be greatly appreciated.

6. **Testing**: Writing and improving unit tests for the library is another way to contribute. Good test coverage ensures the reliability of the library and helps catch bugs early. You can write tests for existing functions or contribute tests for new features you're adding.

7. **Providing Feedback**: If you're using C-STL in your projects, we'd love to hear about your experience! Your feedback can help shape the future direction of the library. Share your thoughts on the API design, performance, and any other aspect of the library.

8. **Spreading the Word**: If you find this library useful, consider sharing it with others! Whether it's through social media, blog posts, or talks at conferences, your endorsement can help grow the community around C-STL.

Thank you for your interest in contributing to C-STL! We look forward to your participation in the project. If you have any questions or need guidance, feel free to reach out to the maintainers by opening an issue or contacting us through the project's communication channels.
