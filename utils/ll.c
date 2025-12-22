#include "../include/linkedlist.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err_list_empty(void) {
    fprintf(stderr, "Error: The linked list is empty.\n");
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

    node_t* ptr = head_ptr;
    while (ptr != NULL) {
        printf("%s", ptr->value);
        if (ptr->next) {
            printf(" -> ");
        }
        ptr = ptr->next;
        // ptr->next->value in the next run
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
    new_node->value = strdup(value);
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
    //* Returns the pointer to the node before the inserted node, or the head pointer if the list was empty
    if (!head_ptr) {
        head_ptr = node;
        return head_ptr;
    }

    node_t* active_node = head_ptr;
    while (active_node->next) {
        // walking the linked list
        active_node = active_node->next;
    }

    active_node->next = node;
    return active_node;
}

node_t* search_by_value(node_t* head_ptr, const char* value) {
    //* Returns pointer to the node with this value, else returns NULL pointer
    if (!head_ptr) {
        err_list_empty();
        return NULL;
    }

    node_t* active_node = head_ptr;
    while (active_node) {
        if (compare(active_node->value, value)) {
            return active_node;
        }
        active_node = active_node->next;
    }

    return NULL;
}

void delete_by_value(node_t** head_ptr, const char* value) {
    if (!*head_ptr) {
        err_list_empty();
        return;
    }

    node_t* active = (*head_ptr)->next;
    if (compare((*head_ptr)->value, value)) {
        free((*head_ptr)->value);
        free(*head_ptr);
        *head_ptr = active;

        return;
    }
    node_t* previous = *head_ptr;

    while (active) {
        if (compare(active->value, value)) {
            // This connects the previous node to the next node
            // Disconnecting the current one
            previous->next = active->next;
            free(active->value);
            free(active);
            return;
        }
        previous = active;
        active = active->next;
    }
}

void prune_all_nodes(node_t** head_ptr) {
    if (!*head_ptr) {
        err_list_empty();
        return;
    }

    node_t* active = *head_ptr;
    while (active) {
        node_t* next = active->next;
        free(active->value);
        free(active);
        active = next;
    }
    *head_ptr = NULL;
}
