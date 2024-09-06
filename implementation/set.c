// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "set.h"

// // Helper function to create a new node
// static AVLNode* create_node(const void* data, size_t size) {
//     AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
//     if (!node) {
//         return NULL;
//     }
//     if (size == sizeof(char*)) {  
//         char* str = *(char**)data;  
//         node->data = malloc(strlen(str) + 1);
//         if (!node->data) {
//             free(node);
//             return NULL;
//         }
//         strcpy((char*)node->data, str);  
//     } else {
//         node->data = malloc(size);
//         if (!node->data) {
//             free(node);
//             return NULL;
//         }
//         memcpy(node->data, data, size);
//     }
//     node->left = node->right = NULL;
//     node->height = 1;  // New node is initially a leaf
//     return node;
// }

// // Helper function to get height of a node
// static int height(AVLNode* node) {
//     return node ? node->height : 0;
// }

// // Helper function to get the balance factor of a node
// static int get_balance(AVLNode* node) {
//     return node ? height(node->left) - height(node->right) : 0;
// }

// // Right rotate subtree rooted with y
// static AVLNode* right_rotate(AVLNode* y) {
//     AVLNode* x = y->left;
//     AVLNode* T2 = x->right;

//     // Perform rotation
//     x->right = y;
//     y->left = T2;

//     // Update heights
//     y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
//     x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

//     return x;  // Return new root
// }

// // Left rotate subtree rooted with x
// static AVLNode* left_rotate(AVLNode* x) {
//     AVLNode* y = x->right;
//     AVLNode* T2 = y->left;

//     // Perform rotation
//     y->left = x;
//     x->right = T2;

//     // Update heights
//     x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
//     y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

//     return y;  // Return new root
// }

// // Helper function to insert a node into the AVL tree
// static AVLNode* avl_insert(AVLNode* node, const void* data, size_t size, compare_fn cmp) {
//     if (!node) {
//         return create_node(data, size);
//     }

//     // Perform regular BST insertion
//     int cmp_result = cmp(data, node->data);
//     if (cmp_result < 0) {
//         node->left = avl_insert(node->left, data, size, cmp);
//     } else if (cmp_result > 0) {
//         node->right = avl_insert(node->right, data, size, cmp);
//     } else {
//         // Duplicate keys are not allowed
//         return node;
//     }

//     // Update the height of the ancestor node
//     node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

//     // Get the balance factor of this ancestor node
//     int balance = get_balance(node);

//     // Left Left Case
//     if (balance > 1 && cmp(data, node->left->data) < 0) {
//         return right_rotate(node);
//     }

//     // Right Right Case
//     if (balance < -1 && cmp(data, node->right->data) > 0) {
//         return left_rotate(node);
//     }

//     // Left Right Case
//     if (balance > 1 && cmp(data, node->left->data) > 0) {
//         node->left = left_rotate(node->left);
//         return right_rotate(node);
//     }

//     // Right Left Case
//     if (balance < -1 && cmp(data, node->right->data) < 0) {
//         node->right = right_rotate(node->right);
//         return left_rotate(node);
//     }

//     return node;  // Return the (unchanged) node pointer
// }

// // Public function to insert into the set
// void set_insert(Set* set, const void* data) {
//     set->root = avl_insert(set->root, data, set->element_size, set->compare);
// }

// // Helper function to find the minimum value node in the AVL tree
// static AVLNode* min_value_node(AVLNode* node) {
//     AVLNode* current = node;
//     while (current->left != NULL) {
//         current = current->left;
//     }
//     return current;
// }

// // Helper function to remove a node from the AVL tree
// static AVLNode* avl_remove(AVLNode* root, const void* data, compare_fn cmp, void (*dstr)(void *), size_t size) {
//     if (!root) {
//         return root;
//     }

//     // Perform standard BST delete
//     int cmp_result = cmp(data, root->data);
//     if (cmp_result < 0) {
//         root->left = avl_remove(root->left, data, cmp, dstr, size);
//     } else if (cmp_result > 0) {
//         root->right = avl_remove(root->right, data, cmp, dstr, size);
//     } else {
//         // Node to be deleted is found
//         if (!root->left || !root->right) {
//             AVLNode* temp = root->left ? root->left : root->right;
//             if (!temp) {
//                 temp = root;
//                 root = NULL;
//             } else {
//                 *root = *temp;  // Copy contents
//             }
//             if (dstr) dstr(temp->data);
//             free(temp->data);
//             free(temp);
//         } else {
//             // Node with two children: Get the inorder successor
//             AVLNode* temp = min_value_node(root->right);
//             memcpy(root->data, temp->data, size);
//             root->right = avl_remove(root->right, temp->data, cmp, dstr, size);
//         }
//     }

//     if (!root) return root;

//     // Update the height of the current node
//     root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

//     // Get the balance factor of this node
//     int balance = get_balance(root);

//     // Balance the tree
//     if (balance > 1 && get_balance(root->left) >= 0) {
//         return right_rotate(root);
//     }
//     if (balance > 1 && get_balance(root->left) < 0) {
//         root->left = left_rotate(root->left);
//         return right_rotate(root);
//     }
//     if (balance < -1 && get_balance(root->right) <= 0) {
//         return left_rotate(root);
//     }
//     if (balance < -1 && get_balance(root->right) > 0) {
//         root->right = right_rotate(root->right);
//         return left_rotate(root);
//     }

//     return root;
// }

// // Public function to remove an element from the set
// void set_remove(Set* set, const void* data) {
//     set->root = avl_remove(set->root, data, set->compare, set->destroy, set->element_size);
// }

// // Helper function to check if a value is in the AVL tree
// static int avl_contains(AVLNode* root, const void* data, compare_fn cmp) {
//     if (!root) {
//         return 0;
//     }
//     int cmp_result = cmp(data, root->data);
//     if (cmp_result == 0) {
//         return 1;
//     } else if (cmp_result < 0) {
//         return avl_contains(root->left, data, cmp);
//     } else {
//         return avl_contains(root->right, data, cmp);
//     }
// }

// // Public function to check if the set contains a given element
// int set_contains(const Set* set, const void* data) {
//     return avl_contains(set->root, data, set->compare);
// }

// // Helper function to destroy the AVL tree
// static void avl_destroy(AVLNode* root, void (*dstr)(void *)) {
//     if (!root) return;
//     avl_destroy(root->left, dstr);
//     avl_destroy(root->right, dstr);
//     if (dstr) dstr(root->data);
//     else free(root->data);
//     free(root);
// }

// // Public function to destroy the set
// void set_destroy(Set* set) {
//     avl_destroy(set->root, set->destroy);
//     free(set);
// }

// // Public function to create a new set
// Set* set_create(compare_fn cmp, void (*dstr)(void *), size_t elem_size) {
//     Set* set = (Set*)malloc(sizeof(Set));
//     if (!set) {
//         return NULL;
//     }
//     set->root = NULL;
//     set->compare = cmp;
//     set->destroy = dstr;
//     set->element_size = elem_size;
//     return set;
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/set.h"

// Helper function to create a new node
static AVLNode* create_node(const void* data, size_t size) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    if (!node) {
        return NULL;
    }
    node->data = malloc(size);
    if (!node->data) {
        free(node);
        return NULL;
    }
    memcpy(node->data, data, size);
    node->left = node->right = NULL;
    node->height = 1;  // New node is initially a leaf
    return node;
}

// Helper function to get height of a node
static int height(AVLNode* node) {
    return node ? node->height : 0;
}

// Helper function to get the balance factor of a node
static int get_balance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotate subtree rooted with y
static AVLNode* right_rotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Left rotate subtree rooted with x
static AVLNode* left_rotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Helper function to insert a node into the AVL tree
static AVLNode* avl_insert(AVLNode* node, const void* data, size_t size, compare_fn cmp) {
    if (!node) {
        return create_node(data, size);
    }

    int cmp_result = cmp(data, node->data);
    if (cmp_result < 0) {
        node->left = avl_insert(node->left, data, size, cmp);
    } else if (cmp_result > 0) {
        node->right = avl_insert(node->right, data, size, cmp);
    } else {
        return node;  // Duplicate keys are not allowed
    }

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && cmp(data, node->left->data) < 0) {
        return right_rotate(node);
    }
    if (balance < -1 && cmp(data, node->right->data) > 0) {
        return left_rotate(node);
    }
    if (balance > 1 && cmp(data, node->left->data) > 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && cmp(data, node->right->data) < 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void set_insert(Set* set, const void* data) {
    set->root = avl_insert(set->root, data, set->element_size, set->compare);
}

static AVLNode* min_value_node(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

static AVLNode* avl_remove(AVLNode* root, const void* data, compare_fn cmp, void (*destroy)(void *), size_t size) {
    if (!root) {
        return root;
    }

    int cmp_result = cmp(data, root->data);
    if (cmp_result < 0) {
        root->left = avl_remove(root->left, data, cmp, destroy, size);
    } else if (cmp_result > 0) {
        root->right = avl_remove(root->right, data, cmp, destroy, size);
    } else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            if (destroy) destroy(temp->data);
            free(temp->data);
            free(temp);
        } else {
            AVLNode* temp = min_value_node(root->right);
            memcpy(root->data, temp->data, size);
            root->right = avl_remove(root->right, temp->data, cmp, destroy, size);
        }
    }

    if (!root) return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = get_balance(root);

    if (balance > 1 && get_balance(root->left) >= 0) {
        return right_rotate(root);
    }
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance < -1 && get_balance(root->right) <= 0) {
        return left_rotate(root);
    }
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void set_remove(Set* set, const void* data) {
    set->root = avl_remove(set->root, data, set->compare, set->destroy, set->element_size);
}

static int avl_contains(AVLNode* root, const void* data, compare_fn cmp) {
    if (!root) {
        return 0;
    }
    int cmp_result = cmp(data, root->data);
    if (cmp_result == 0) {
        return 1;
    } else if (cmp_result < 0) {
        return avl_contains(root->left, data, cmp);
    } else {
        return avl_contains(root->right, data, cmp);
    }
}

int set_contains(const Set* set, const void* data) {
    return avl_contains(set->root, data, set->compare);
}

static void avl_destroy(AVLNode* root, void (*destroy)(void *)) {
    if (!root) return;
    avl_destroy(root->left, destroy);
    avl_destroy(root->right, destroy);
    if (destroy) {
        destroy(root->data);
    }
    free(root);  // We no longer free root->data here
}

void set_destroy(Set* set) {
    avl_destroy(set->root, set->destroy);
    free(set);
}

Set* set_create(compare_fn cmp, void (*destroy)(void *), size_t elem_size) {
    Set* set = (Set*)malloc(sizeof(Set));
    if (!set) {
        return NULL;
    }
    set->root = NULL;
    set->compare = cmp;
    set->destroy = destroy;
    set->element_size = elem_size;
    return set;
}

// New function to get the size of the set
static size_t avl_size(AVLNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + avl_size(root->left) + avl_size(root->right);
}

size_t set_size(const Set* set) {
    return avl_size(set->root);
}