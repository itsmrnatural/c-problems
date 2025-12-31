#ifndef BST_H
#define BST_H
#include <stddef.h>
#include <stdint.h>

struct Node {
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int data;
    uint8_t bfactor;
};

enum rotation_t { LL, RR, LR, RL, NONE};
enum child_t { LEFT, RIGHT };

struct Node* create_bst(void);
struct Node* insert(struct Node* root, int key);
struct Node* search(struct Node* root, int key);
size_t height(struct Node* root);
int8_t balance_factor(struct Node* root);
struct Node* maximum(struct Node* node);
struct Node* minimum(struct Node* node);
struct Node* predecessor(struct Node* root);
struct Node* successor(struct Node* root);
void delete_node(struct Node* root, int key);
void inorder_trav(struct Node* root);
void preorder_trav(struct Node* root);
void postorder_trav(struct Node* root);
void leftleft(struct Node* root);
void rightright(struct Node* root);
void leftright(struct Node* root);
void rightleft(struct Node* root);
enum rotation_t balance_rotation(struct Node* node);
void autobalance(struct Node* node);

#endif
