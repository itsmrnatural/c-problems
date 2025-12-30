#include "../include/bst.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int8_t balance_factor(struct Node* root);

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

struct Node* create_bst(void) {
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    if (!root) {
        fprintf(stderr, "Memory allocation failed for BST.\n");
        return NULL;
    }
    return root;
}

/* Returns the root. */
struct Node* insert(struct Node* root, int key) {
    if (!root) {
        struct Node* new_leaf = (struct Node*) malloc(sizeof(struct Node));
        if (new_leaf == NULL) {
            fprintf(stderr, "Memory allocation failed for new node.\n");
            return NULL;
        }
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return new_leaf;
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
        root->left->parent = root;  // In my words, umblicating the child
    } else {
        root->right = insert(root->right, key);
        root->right->parent = root;  // In my words, umblicating the child
    }
    int8_t node_bfactor = balance_factor(root);
    if (abs(node_bfactor) >= 2) {
        autobalance(root);
    }
    return root;
}

/* Returns (struct Node*) pointer to the node with matched value. */
struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

/* Returns the height of the tree (from the node). */
size_t height(struct Node* root) {
    if (!root) return 0;
    return (1 + height(root->left) + height(root->right));
}

/* Calculate and stores current balance factor for the node. */
int8_t balance_factor(struct Node* root) {
    root->bfactor = (height(root->left) - height(root->right));
    return root->bfactor;
}

/* Finds maximum valued leaf (struct Node*) from a root. */
struct Node* maximum(struct Node* node) {
    while (node->right != NULL)
        node = node->right;
    return node;
}

/* Finds minimum valued leaf (struct Node*) from a root. */
struct Node* minimum(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

/* Finds the inorder predecessor of a node. */
struct Node* predecessor(struct Node* root) {
    if (!root->left) {
        struct Node* p_child = root;
        struct Node* p_parent = root->parent;

        int child_data = p_child->data;
        int parent_data = p_parent->data;
        while (child_data < parent_data) {
            p_child = p_parent;
            p_parent = p_child->parent;
            if (!p_parent) return NULL;  // Probably the upmost root arrived
        }
        return p_parent;  // This is the inorder predecessor of root node.
    }
    return maximum(root->left);
}

/* Finds the inorder succesor of a node. */
struct Node* successor(struct Node* root) {
    if (!root->right) {
        struct Node* p_child = root;
        struct Node* p_parent = root->parent;

        int child_data = p_child->data;
        int parent_data = p_parent->data;
        while (child_data > parent_data) {
            p_child = p_parent;
            p_parent = p_child->parent;
            if (!p_parent) return NULL;  // Probably the upmost root arrived
        }
        return p_parent;  // This is the inorder successor of root node.
    }

    return minimum(root->right);
}

/* Deletes a node by value simple. */
void delete_node(struct Node* root, int key) {
    // TODO change how predecessor and successor are determined after implementing
    // TODO balancing factor

    if (!root) return;

    struct Node* target = search(root, key);
    if (!target->left && !target->right) {
        free(target);
    }

    size_t height_left = height(target->left);
    size_t height_right = height(target->right);

    struct Node* replacement;
    if (height_left < height_right) {
        replacement = minimum(target->right);
    } else {
        replacement = maximum(target->left);
    }

    int new_key = replacement->data;
    delete_node(replacement, replacement->data);
    target->data = new_key;
}

/* Traversals */
/* Inorder traversal (left -> root -> right) */
void inorder_trav(struct Node* root) {
    if (!root) return;

    inorder_trav(root->left);
    printf("%d", root->data);
    inorder_trav(root->right);
}

/* Preorder traversal (root -> left -> right) */
void preorder_trav(struct Node* root) {
    if (!root) return;

    printf("%d", root->data);
    preorder_trav(root->left);
    preorder_trav(root->right);
}

/* Postorder traversal (left -> right -> root) */
void postorder_trav(struct Node* root) {
    if (!root) return;

    postorder_trav(root->left);
    postorder_trav(root->right);
    printf("%d", root->data);
}

/* Peforms a right rotation on the node given to balance it. */
void leftleft(struct Node* root) {
    /*
        Performed on a node with BF = +2
        with left child BF = +1/0
    */
    struct Node* p_parent = root;
    struct Node* p_child = p_parent->left;

    swap(&p_child->data, &p_parent->data);
    p_parent->right = p_child;
    p_parent->left = p_child->left;
}

/* Peforms a left rotation on the node given to balance it. */
void rightright(struct Node* root) {
    /*
        Performed on a node with BF = -2
        with right child BF = -1/0
    */
    struct Node* p_parent = root;
    struct Node* p_child = p_parent->right;

    swap(&p_child->data, &p_parent->data);
    p_parent->left = p_child;
    p_parent->right = p_child->right;
}

/* Peforms a left-right rotation on the node given to balance it. */
void leftright(struct Node* root) {
    /*
        Performed on a node with BF = +2
        with right child BF = -1/0
    */
    struct Node* p_parent = root;
    struct Node* p_child = p_parent->left;
    struct Node* p_grandcl = p_child->right;

    swap(&p_grandcl->data, &p_parent->data);
    p_child->right = NULL;
    p_parent->right = p_grandcl;
}

/* Peforms a left-right rotation on the node given to balance it. */
void rightleft(struct Node* root) {
    /*
        Performed on a node with BF = -2
        with right child BF = +1/0
    */
    struct Node* p_parent = root;
    struct Node* p_child = p_parent->right;
    struct Node* p_grandcl = p_child->left;

    swap(&p_grandcl->data, &p_parent->data);
    p_child->left = NULL;
    p_parent->left = p_grandcl;
}

/* Determines and returns the type of rotation_t need to balance the given node. */
enum rotation_t balance(struct Node* node) {
    int8_t node_bfactor = node->bfactor;
    int8_t lchild_bfactor = node->left->bfactor;
    int8_t rchild_bfactor = node->right->bfactor;

    if (abs(node_bfactor) < 2) {
        return NULL;
    } else if (node_bfactor == 2) {
        return (lchild_bfactor >= 0) ? LL : LR;
    } else if (node_bfactor == -2) {
        return (rchild_bfactor <= 0) ? RR : RL;
    }
    return NULL;
}

/* Auto-balances the passed node with the required rotation. */
void autobalance(struct Node* node) {
    enum rotation_t rotation = balance(node);
    switch (rotation) {
        case LL:
            leftleft(node);
            break;
        case LR:
            leftright(node);
            break;
        case RR:
            leftright(node);
            break;
        case RL:
            leftright(node);
            break;
        default:
            // Node doesn't need balancing
            return;
    }
}