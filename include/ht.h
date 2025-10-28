#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct entry_t {
    char* key;
    void* value;
    struct entry_t* next;
} entry_t;

typedef struct {
    entry_t** buckets;
    size_t len;
    size_t size;
} ht_t;  // was hashtable_t shortened to ht_t :C

ht_t* ht_create(size_t size);
bool ht_destroy(ht_t* table);
ht_t* ht_resize(ht_t* table, uint8_t factor);
ht_t* ht_clear(ht_t* table);

bool ht_set(ht_t* table, char* key, void* value);
entry_t* ht_get(ht_t* table, char* key);
bool ht_has(ht_t* table, char* key);
bool ht_delete(ht_t* table, char* key);
entry_t* ht_update(ht_t* table, char* key, void* value);
char** ht_keys(ht_t* table);

#endif