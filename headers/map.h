#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int int_hash(const void *key);
int string_hash(const void *key);
int float_hash(const void *key);

typedef int (*hash_fn)(const void* key);         
typedef int (*compare_fn)(const void* a, const void* b); 

typedef struct HashNode {
    void *key;               
    void *value;             
    struct HashNode *next;   
} HashNode;

typedef struct HashMap {
    HashNode **buckets;      
    size_t capacity;         
    size_t size;             
    size_t key_size;         
    size_t value_size;       
    hash_fn hash;            
    compare_fn compare;      
} HashMap;

HashMap *hashmap_create(size_t capacity, size_t key_size, size_t value_size, hash_fn hash, compare_fn compare);
void hashmap_insert(HashMap *map, const void *key, const void *value);
void *hashmap_get(HashMap *map, const void *key);
bool hashmap_remove(HashMap *map, const void *key);
bool hashmap_contains(HashMap *map, const void *key);
void hashmap_clear(HashMap *map);
void hashmap_destroy(HashMap *map);

#endif // HASHMAP_H
