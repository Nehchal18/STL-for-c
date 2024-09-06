#include "../headers/priority_queue.h"

// Initialize the heap with a comparison function
void heap_init(heap *h, size_t elem_size, int (*compare)(const void*, const void*)) {
    vector_init(&h->vec, elem_size);   // Use the vector's initialization function
    h->compare = compare;
}

// Heapify up to maintain the heap property
void heapify_up(heap *h, size_t index) {
    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if (h->compare(vector_get(&h->vec, index), vector_get(&h->vec, parent)) < 0) {
            void *temp = malloc(h->vec.elem_size);
            memcpy(temp, vector_get(&h->vec, index), h->vec.elem_size);
            memcpy(vector_get(&h->vec, index), vector_get(&h->vec, parent), h->vec.elem_size);
            memcpy(vector_get(&h->vec, parent), temp, h->vec.elem_size);
            free(temp);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify down to maintain the heap property
void heapify_down(heap *h, size_t index) {
    size_t left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;
        
        if (left < h->vec.size && h->compare(vector_get(&h->vec, left), vector_get(&h->vec, smallest)) < 0) {
            smallest = left;
        }
        if (right < h->vec.size && h->compare(vector_get(&h->vec, right), vector_get(&h->vec, smallest)) < 0) {
            smallest = right;
        }
        if (smallest != index) {
            void *temp = malloc(h->vec.elem_size);
            memcpy(temp, vector_get(&h->vec, index), h->vec.elem_size);
            memcpy(vector_get(&h->vec, index), vector_get(&h->vec, smallest), h->vec.elem_size);
            memcpy(vector_get(&h->vec, smallest), temp, h->vec.elem_size);
            free(temp);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert an element into the heap
void heap_push(heap *h, const void *value) {
    vector_push_back(&h->vec, value);
    heapify_up(h, h->vec.size - 1);
}

// Remove the top element from the heap
void heap_pop(heap *h) {
    if (h->vec.size > 0) {
        memcpy(vector_get(&h->vec, 0), vector_get(&h->vec, h->vec.size - 1), h->vec.elem_size);
        vector_pop_back(&h->vec);
        heapify_down(h, 0);
    }
}

// Return the top element of the heap (min or max)
void *heap_top(heap *h) {
    if (h->vec.size > 0) {
        return vector_get(&h->vec, 0);
    }
    return NULL; // Heap is empty
}

// Check if the vector is a heap
bool vector_is_heap(vector *v, int (*compare)(const void*, const void*)) {
    for (size_t i = 0; i < v->size / 2; i++) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < v->size && compare(vector_get(v, i), vector_get(v, left)) > 0) {
            return false;
        }
        if (right < v->size && compare(vector_get(v, i), vector_get(v, right)) > 0) {
            return false;
        }
    }
    return true; 
}

// Free the heap
void heap_free(heap *h) {
    vector_free(&h->vec);
}

// Initialize the priority queue (min-heap by default)
void priority_queue_init(priority_queue *pq, size_t elem_size, int (*compare)(const void*, const void*)) {
    heap_init(pq, elem_size, compare);
}

// Insert an element into the priority queue
void priority_queue_push(priority_queue *pq, const void *value) {
    heap_push(pq, value);
}

// Remove the element with the highest priority (min or max)
void priority_queue_pop(priority_queue *pq) {
    heap_pop(pq);
}

// Get the element with the highest priority (min or max)
void *priority_queue_top(priority_queue *pq) {
    return heap_top(pq);
}

// Check if the priority queue is empty
bool priority_queue_empty(priority_queue *pq) {
    return vector_empty(&pq->vec);
}

// Free the priority queue
void priority_queue_free(priority_queue *pq) {
    heap_free(pq);
}
