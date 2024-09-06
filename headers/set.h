#ifndef SET_H
#define SET_H

#include <stddef.h>

typedef int (*compare_fn)(const void*, const void*);  // Compare function
// typedef void (*destroy_fn)(void*);                    // Destroy function

typedef struct AVLNode {
    void* data;               // Pointer to the data
    struct AVLNode* left;     // Left child
    struct AVLNode* right;    // Right child
    int height;               // Height of the node
} AVLNode;

typedef struct Set {
    AVLNode* root;            // Root of the AVL tree
    compare_fn compare;       // Function pointer to compare elements
    void (*destroy)(void *);       // Function pointer to destroy elements
    size_t element_size;      // Size of each element
} Set;

// Function declarations
Set* set_create(compare_fn cmp, void (*destroy)(void *), size_t elem_size);
void set_insert(Set* set, const void* data);
void set_remove(Set* set, const void* data);
int set_contains(const Set* set, const void* data);
void set_destroy(Set* set);
size_t set_size(const Set* set);

#endif // SET_H
