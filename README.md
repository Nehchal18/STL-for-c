# C-STL: A Simple STL-like Library for C

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Vector](#vector)
  - [List](#list)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Map](#map)
- [Examples](#examples)
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

## Usage

### Vector

Vectors in C-STL are dynamic arrays that automatically resize as elements are added or removed. They provide an efficient way to manage collections of data with random access.

```c
#include "vector.h"

int main() {

    // Before using a vector, you need to initialize it. This sets the initial size to 0 and the capacity to 4.
    Vector vec;
    vector_init(&vec);

    // Add elements to the vector
    vector_push_back(&vec, 10);
    vector_push_back(&vec, 20);

    // Front Element: Access the first element.
    int front = vector_front(&vec);

    // Pop Back: Remove the last element from the vector.
    vector_int_pop_back(&vec);

    // Back Element: Access the last element.
    int back = vector_back(&vec);

    // Element by Index: Access an element at a specific index.
    int value = vector_int_get(&vec, 2);

    // Reverse the Vector: Reverse the order of elements in the vector.
    vector_int_reverse(&vec);

    // Size: Get the number of elements in the vector.
    size_t size = vector_int_size(&vec);

    // Capacity: Get the capacity of the vector (the total number of elements it can hold before resizing).
    size_t capacity = vector_int_capacity(&vec);

    // Check if Empty: Check if the vector is empty.
    bool is_empty = vector_int_empty(&vec);

    // Find an Element: Find the index of an element. Returns -1 if the element is not found.
    int index = vector_int_find(&vec, 20);

    // Clear: Remove all elements from the vector, but retain its capacity.
    vector_int_clear(&vec);

    // Free: Free the memory allocated to the vector.
    vector_free(&vec);

    return 0;
}
```

### List

C-STL's linked list implementation supports both singly and doubly linked lists, allowing for flexible insertion and deletion of elements.

```c
#include "list.h"

int main() {
    List list;
    list_init(&list);

    // Add elements to the list
    list_push_back(&list, 10);
    list_push_front(&list, 20);

    // Iterate over the list
    ListNode *node = list.head;
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }

    list_free(&list);
    return 0;
}
```

### Stack

Stacks in C-STL provide a LIFO (Last In, First Out) structure, useful for scenarios like function call management and expression evaluation.

```c
#include "stack.h"

int main() {
    Stack stack;
    stack_init(&stack);

    // Push elements onto the stack
    stack_push(&stack, 10);
    stack_push(&stack, 20);

    // Pop an element from the stack
    int top = stack_pop(&stack);

    stack_free(&stack);
    return 0;
}
```

### Queue

Queues in C-STL implement a FIFO (First In, First Out) data structure, suitable for tasks like task scheduling and breadth-first search.

```c
#include "queue.h"

int main() {
    Queue queue;
    queue_init(&queue);

    // Enqueue elements
    queue_enqueue(&queue, 10);
    queue_enqueue(&queue, 20);

    // Dequeue an element
    int front = queue_dequeue(&queue);

    queue_free(&queue);
    return 0;
}
```

### Map

Maps (associative arrays) in C-STL allow you to store and retrieve key-value pairs efficiently. **(Note: Implementation in progress)**

```c
#include "map.h"

int main() {
    Map map;
    map_init(&map);

    // Insert key-value pairs
    map_insert(&map, "key1", 100);
    map_insert(&map, "key2", 200);

    // Retrieve a value by key
    int value = map_get(&map, "key1");

    map_free(&map);
    return 0;
}
```

## Examples

Here are some example programs that demonstrate the usage of the C-STL library:

- **Sorting a Vector**:
  ```c
  #include "vector.h"
  #include "sort.h"

  int main() {
      Vector vec;
      vector_init(&vec);

      vector_push_back(&vec, 3);
      vector_push_back(&vec, 1);
      vector_push_back(&vec, 2);

      quicksort(&vec);

      vector_free(&vec);
      return 0;
  }
  ```

- **Using a Stack for Expression Evaluation**:
  ```c
  #include "stack.h"

  int evaluate_expression(const char* expr);

  int main() {
      const char* expr = "3 4 + 2 * 7 /";
      int result = evaluate_expression(expr);

      printf("Result: %d\n", result);
      return 0;
  }
  ```

- **Priority Queue for Task Scheduling**:
  ```c
  #include "priority_queue.h"

  int main() {
      PriorityQueue pq;
      priority_queue_init(&pq);

      priority_queue_push(&pq, 1, "Task 1");
      priority_queue_push(&pq, 2, "Task 2");

      char* task = priority_queue_pop(&pq);

      priority_queue_free(&pq);
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
