/*
    Requirements:
    Node structure: value and next pointer
    Operations:
        Insert at head
        Insert at tail
        Delete a node by value
        Search for a value
        Print the list
        Free all nodes (avoid memory leaks)
        Test each operation thoroughly
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type definations
typedef struct node_t {
    char* value;
    /// For the next to be declared as a node_t pointer we need to name the struct, no anonymous naming.
    struct node_t* next;
} node_t;
// typedef node_t* node_ptr; // Unused!

// Function Prototypes
/// General
bool compare(const char*, const char*);

/// Node specific
void print_nodes(node_t*);
node_t* create_node(char*);
node_t* insert_at_head(node_t*, node_t*);
node_t* insert_at_tail(node_t*, node_t*);
node_t* search_by_value(node_t*, const char*);
node_t* delete_by_value(node_t*, const char*);
node_t* prune_all_nodes(node_t*);

// Function Definations
int main(void) {
    node_t* head_ptr = NULL;  // [HEAD] -> [NULL]

    printf("Linked List Program Simulation");
    printf("\t1. Print all nodes");
    printf("\t2. Insert at head");
    printf("\t3. Insert at tail");
    printf("\t4. Search by value");
    printf("\t5. Delete by value");
    printf("\t6. Prune all nodes");
    printf("\t7. Exit");
    // ... to be made ...
    return 0;
}

bool compare(const char* value1, const char* value2) {
    // Returns true when equal, else false
    return (strcmp(value1, value2) == 0);
}

void print_nodes(node_t* head_ptr) {
    //* Prints all nodes in (value1 -> value2 -> ...) form
    if (!head_ptr) {
        //
        return;
    }

    node_t* current_ptr = head_ptr;
    while (current_ptr != NULL) {
        printf("%s", current_ptr->value);
        if (current_ptr->next != NULL) {
            printf(" -> ");
        }
        current_ptr = current_ptr->next;
    }
    printf("\n");
}

node_t* create_node(char* value) {
    //* Returns a pointer to the newly created node
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

node_t* insert_at_head(node_t* head_ptr, node_t* node) {
    //* Returns the head pointer
    if (!head_ptr) {
        head_ptr = node;
        return head_ptr;
    }

    // Head pointer already points to a node move it by one.
    node->next = head_ptr;
    head_ptr = node;
    return head_ptr;
}

node_t* insert_at_tail(node_t* head_ptr, node_t* node) {
    //* Returns the pointer to the current inserted node (Useless?)
    if (!head_ptr) {
        head_ptr = node;
        return head_ptr;
    }

    node_t* current_ptr = head_ptr;
    while (current_ptr != NULL) {
        current_ptr = current_ptr->next;
    }

    current_ptr = node;
    return current_ptr;
}

node_t* search_by_value(node_t* head_ptr, const char* value) {
    //* Returns pointer to the node with this value, else returns NULL pointer
    if (!head_ptr) {
        // Handle empty linked list error.
        return NULL;
    }

    node_t* current_node = head_ptr;

    while (current_node != NULL) {
        if (compare(current_node->value, value)) {
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

node_t* delete_by_value(node_t* head_ptr, const char* value) {
    //* For safety returns the head pointer after the delete operation
    if (!head_ptr) {
        //
        return NULL;
    }

    node_t* current_node = head_ptr;

    while (current_node != NULL) {
        if (compare(current_node->value, value)) {
        }
    }
}

node_t* prune_all_nodes(node_t* head_ptr) {
}