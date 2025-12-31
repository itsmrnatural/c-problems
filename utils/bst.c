#include "../include/bst.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Intializes the BST and returns the pointer to root that you'll have to store. */
struct Node* create_bst(void) {
    return NULL;
}

/* Returns the root. */
struct Node* insert(struct Node* root, int key) {
    if (!root) {
        struct Node* new_leaf = (struct Node*) malloc(sizeof(struct Node));
        if (new_leaf == NULL) {
            fprintf(stderr, "Memory allocation failed for new node.\n");
            return NULL;
        }
        new_leaf->data = key;
        new_leaf->left = NULL;
        new_leaf->right = NULL;
        new_leaf->parent = NULL;
        return new_leaf;
    }

    if (key == root->data) {
        fprintf(stderr, "Can't insert duplicate values in the BST.");
        return root;
    } else if (key < root->data) {
        root->left = insert(root->left, key);
        root->left->parent = root;  // In my words, umblicating the child
    } else {
        root->right = insert(root->right, key);
        root->right->parent = root;  // In my words, umblicating the child
    }
    int8_t node_bfactor = balance_factor(root);
    if (abs(node_bfactor) >= 2) {
        root = autobalance(root);
    }
    return root;
}

/* Returns (struct Node*) pointer to the node with matched value. */
struct Node* search(struct Node* root, int key) {
    if (!root) return NULL;
    if (root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

/* Returns the height of the tree (from the node). */
size_t height(struct Node* node) {
    if (!node) return 0;
    size_t lheight = height(node->left);
    size_t rheight = height(node->right);
    return (1 + (lheight > rheight ? lheight : rheight));
}

/* Calculate and stores current balance factor for the node. */
int8_t balance_factor(struct Node* root) {
    if (!root) return 0;
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
        struct Node* child = root;
        struct Node* parent = root->parent;
        if (!parent) return NULL;

        int child_data = child->data;
        int parent_data = parent->data;
        while (child_data < parent_data) {
            child = parent;
            parent = child->parent;
            child_data = child->data;
            parent_data = parent->data;
            if (!parent) return NULL;  // Probably the upmost root arrived
        }
        return parent;  // This is the inorder predecessor of root node.
    }
    return maximum(root->left);
}

/* Finds the inorder succesor of a node. */
struct Node* successor(struct Node* root) {
    if (!root->right) {
        struct Node* child = root;
        struct Node* parent = root->parent;
        if (!parent) return NULL;

        int child_data = child->data;
        int parent_data = parent->data;
        while (child_data > parent_data) {
            child = parent;
            parent = child->parent;
            child_data = child->data;
            parent_data = parent->data;
            if (!parent) return NULL;  // Probably the upmost root arrived
        }
        return parent;  // This is the inorder successor of root node.
    }
    return minimum(root->right);
}

/* Deletes a node by value simple. */
void delete_node(struct Node* root, int key) {
    if (!root) return;

    struct Node* target = search(root, key);
    if (!target) {
        fprintf(stderr, "Can't delete key which doesn't exist.");
        return;
    }

    if (!target->left && !target->right) {
        struct Node* parent = target->parent;
        if (parent) {
            if (parent->left == target) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            while (parent) {
                parent = autobalance(parent);
                parent = parent->parent;
            }
        }
        free(target);
        return;
    }

    struct Node* replacement;
    int8_t bfactor = balance_factor(target);
    if (bfactor < 0) {
        replacement = minimum(target->right);
    } else {
        replacement = maximum(target->left);
    }

    int new_key = replacement->data;
    struct Node* parent = replacement->parent;
    delete_node(replacement, replacement->data);
    while (parent) {
        parent = autobalance(parent);
        parent = parent->parent;
    }
    target->data = new_key;
}

/* Traversals */
/* Inorder traversal (left -> root -> right) */
void inorder_trav(struct Node* root) {
    if (!root) return;

    inorder_trav(root->left);
    printf("%d ", root->data);
    inorder_trav(root->right);
}

/* Preorder traversal (root -> left -> right) */
void preorder_trav(struct Node* root) {
    if (!root) return;

    printf("%d ", root->data);
    preorder_trav(root->left);
    preorder_trav(root->right);
}

/* Postorder traversal (left -> right -> root) */
void postorder_trav(struct Node* root) {
    if (!root) return;

    postorder_trav(root->left);
    postorder_trav(root->right);
    printf("%d ", root->data);
}

/* Peforms a right rotation on the node given to balance it. */
void leftleft(struct Node* root) {
    /*
        Performed on a node with BF = +2
        with left child BF = +1/0
    */
    struct Node* pivot = root->left;
    struct Node* subtree = pivot->right;
    struct Node* parent = root->parent;

    root->left = subtree;
    if (subtree) subtree->parent = root;
    pivot->right = root;
    pivot->parent = parent;
    root->parent = pivot;
    if (parent) {
        if (parent->left == root)
            parent->left = pivot;
        else
            parent->right = pivot;
    }
    balance_factor(root);
    balance_factor(pivot);
    balance_factor(parent);
}

/* Peforms a left rotation on the node given to balance it. */
void rightright(struct Node* root) {
    /*
        Performed on a node with BF = -2
        with right child BF = -1/0
    */
    struct Node* pivot = root->right;
    struct Node* subtree = pivot->left;
    struct Node* parent = root->parent;

    root->right = subtree;
    if (subtree) subtree->parent = root;
    pivot->left = root;
    pivot->parent = parent;
    root->parent = pivot;
    if (parent) {
        if (parent->left == root)
            parent->left = pivot;
        else
            parent->right = pivot;
    }
    balance_factor(root);
    balance_factor(pivot);
    balance_factor(parent);
}

/* Peforms a left-right rotation on the node given to balance it. */
void leftright(struct Node* root) {
    /*
        Performed on a node with BF = +2
        with right child BF = -1/0
    */
    rightright(root->left);
    leftleft(root);
}

/* Peforms a right-left rotation on the node given to balance it. */
void rightleft(struct Node* root) {
    /*
        Performed on a node with BF = -2
        with right child BF = +1/0
    */
    leftleft(root->right);
    rightright(root);
}

/* Determines and returns the type of rotation_t need to balance the given node. */
enum rotation_t rotation_type(struct Node* node) {
    int8_t node_bfactor = balance_factor(node);
    int8_t lchild_bfactor = balance_factor(node->left);
    int8_t rchild_bfactor = balance_factor(node->right);

    if (abs(node_bfactor) < 2) {
        return NONE;
    } else if (node_bfactor == 2) {
        return (lchild_bfactor >= 0) ? LL : LR;
    } else if (node_bfactor == -2) {
        return (rchild_bfactor <= 0) ? RR : RL;
    }
    return NONE;
}

/* Auto-balances the passed node with the required rotation. */
struct Node* autobalance(struct Node* node) {
    enum rotation_t rotation = rotation_type(node);
    switch (rotation) {
        case LL:
            leftleft(node);
            return node->parent ? node->parent : node;
        case LR:
            leftright(node);
            return node->parent ? node->parent : node;
        case RR:
            rightright(node);
            return node->parent ? node->parent : node;
        case RL:
            rightleft(node);
            return node->parent ? node->parent : node;
        default:
            // Node doesn't need balancing
            return node;
    }
}