#include "../include/linkedlist.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err_list_empty(void) {
    fprintf(stderr, "Error: The linked list is empty.");
}

bool compare(const char* value1, const char* value2) {
    // Returns true when equal, else false
    return (strcmp(value1, value2) == 0);
}

void print_nodes(node_t* head_ptr) {
    //* Prints all nodes in (value1 -> value2 -> ...) form
    if (!head_ptr) {
        err_list_empty();
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
        err_list_empty();
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
    //* Returns pointer to the element before the element deleted
    //* Returns NULL pointer if operation failed
    if (!head_ptr) {
        err_list_empty();
        return NULL;
    }

    node_t* prev_node = head_ptr;     // Using as a default pointer to
    node_t* current_node = head_ptr;  // return if first node itself matches

    while (current_node != NULL) {
        if (compare(current_node->value, value)) {
            // This connects the previous node to the next node
            // Disconnecting the current one
            prev_node = current_node->next;
            free(current_node);
            return prev_node;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }

    return NULL;
}

void prune_all_nodes(node_t* head_ptr) {
    if (!head_ptr) {
        err_list_empty();
        return;
    }

    node_t* current_ptr = head_ptr;
    while (current_ptr != NULL) {
        // current_ptr gets head_ptr each time
        current_ptr = delete_by_value(current_ptr, current_ptr->value);
    }
}
