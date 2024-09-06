#include "../headers/map.h"

// Create a new hashmap
HashMap *hashmap_create(size_t capacity, size_t key_size, size_t value_size, hash_fn hash, compare_fn compare) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->buckets = (HashNode **)calloc(capacity, sizeof(HashNode *));
    map->capacity = capacity;
    map->size = 0;
    map->key_size = key_size;
    map->value_size = value_size;
    map->hash = hash;
    map->compare = compare;
    return map;
}

// Create a new hash node
HashNode *hashnode_create(const void *key, const void *value, size_t key_size, size_t value_size) {
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = malloc(key_size);
    node->value = malloc(value_size);
    memcpy(node->key, key, key_size);
    memcpy(node->value, value, value_size);
    node->next = NULL;
    return node;
}

// Insert key-value pair into the hashmap
void hashmap_insert(HashMap *map, const void *key, const void *value) {
    int index = map->hash(key) % map->capacity;
    HashNode *node = hashnode_create(key, value, map->key_size, map->value_size);

    if (!map->buckets[index]) {
        map->buckets[index] = node;
    } else {
        HashNode *current = map->buckets[index];
        while (current->next && map->compare(current->key, key) != 0) {
            current = current->next;
        }

        if (map->compare(current->key, key) == 0) {
            memcpy(current->value, value, map->value_size); // Replace value if key exists
            free(node->key);
            free(node->value);
            free(node);
            return;
        }

        current->next = node;
    }
    map->size++;
}

// Get value from hashmap by key
void *hashmap_get(HashMap *map, const void *key) {
    int index = map->hash(key) % map->capacity;
    HashNode *current = map->buckets[index];

    while (current) {
        if (map->compare(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Key not found
}

// Remove a key-value pair from the hashmap
bool hashmap_remove(HashMap *map, const void *key) {
    int index = map->hash(key) % map->capacity;
    HashNode *current = map->buckets[index];
    HashNode *prev = NULL;

    while (current) {
        if (map->compare(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                map->buckets[index] = current->next;
            }

            free(current->key);
            free(current->value);
            free(current);
            map->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false; // Key not found
}

// Check if a key exists in the hashmap
bool hashmap_contains(HashMap *map, const void *key) {
    return hashmap_get(map, key) != NULL;
}

// Clear all elements from the hashmap
void hashmap_clear(HashMap *map) {
    for (size_t i = 0; i < map->capacity; i++) {
        HashNode *current = map->buckets[i];
        while (current) {
            HashNode *to_delete = current;
            current = current->next;
            free(to_delete->key);
            free(to_delete->value);
            free(to_delete);
        }
        map->buckets[i] = NULL;
    }
    map->size = 0;
}

// Destroy the hashmap and free all memory
void hashmap_destroy(HashMap *map) {
    hashmap_clear(map);
    free(map->buckets);
    free(map);
}

int int_hash(const void *key) {
    return *(int *)key;
}

int string_hash(const void *key) {
    const char *str = (const char *)key;
    int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str;
        str++;
    }
    return hash;
}

int float_hash(const void *key) {
    float value = *(float *)key;
    return *(int *)&value;
}