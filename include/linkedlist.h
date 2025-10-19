#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

// Type definition
typedef struct node_t {
    char* value;
    struct node_t* next;
} node_t;

// Function prototypes (interface)
bool compare(const char*, const char*);

void print_nodes(node_t*);
node_t* create_node(char*);
node_t* insert_at_head(node_t*, node_t*);
node_t* insert_at_tail(node_t*, node_t*);
node_t* search_by_value(node_t*, const char*);
node_t* delete_by_value(node_t*, const char*);
void prune_all_nodes(node_t*);

#endif