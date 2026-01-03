#include "../include/bst.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_tree_helper(struct Node* node, char* prefix, bool is_left) {
    //! This function wasnt written by me.
    if (!node) return;

    printf("%s", prefix);
    printf("%s", is_left ? "├── " : "└── ");
    printf("%d\n", node->data);

    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix,
             is_left ? "│   " : "    ");

    if (node->left || node->right) {
        if (node->left) {
            print_tree_helper(node->left, new_prefix, node->right != NULL);
        } else if (node->right) {
            printf("%s├── (null)\n", new_prefix);
        }

        if (node->right) {
            print_tree_helper(node->right, new_prefix, false);
        } else if (node->left) {
            printf("%s└── (null)\n", new_prefix);
        }
    }
}

void print_tree(struct Node* root) {
    if (!root) {
        printf("Tree is empty\n");
        return;
    }
    printf("%d\n", root->data);
    if (root->left || root->right) {
        if (root->left) {
            print_tree_helper(root->left, "", root->right != NULL);
        } else if (root->right) {
            printf("├── (null)\n");
        }

        if (root->right) {
            print_tree_helper(root->right, "", false);
        } else if (root->left) {
            printf("└── (null)\n");
        }
    }
}

void print_menu(void) {
    printf("\n========== BST Test Menu ==========\n");
    printf("1.  Insert node\n");
    printf("2.  Search node\n");
    printf("3.  Delete node\n");
    printf("4.  Find minimum\n");
    printf("5.  Find maximum\n");
    printf("6.  Find predecessor\n");
    printf("7.  Find successor\n");
    printf("8.  Get height\n");
    printf("9.  Get balance factor\n");
    printf("10. Inorder traversal\n");
    printf("11. Preorder traversal\n");
    printf("12. Postorder traversal\n");
    printf("13. Insert multiple nodes\n");
    printf("14. Print ASCII tree\n");
    printf("0.  Exit\n");
    printf("===================================\n");
    printf("Choose option: ");
}

int main(void) {
    struct Node* root = NULL;
    int choice, value;
    bool running = true;

    printf("BST Testing Kit\n");
    printf("===============\n");

    while (running) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* found = search(root, value);
                if (found) {
                    printf("Found %d in tree\n", value);
                } else {
                    printf("%d not found in tree\n", value);
                }
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_node(root, value);
                printf("Deleted %d (if it existed)\n", value);
                break;

            case 4:
                if (root) {
                    struct Node* min = minimum(root);
                    printf("Minimum value: %d\n", min->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;

            case 5:
                if (root) {
                    struct Node* max = maximum(root);
                    printf("Maximum value: %d\n", max->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;

            case 6:
                printf("Enter node value to find predecessor: ");
                scanf("%d", &value);
                struct Node* node_pred = search(root, value);
                if (node_pred) {
                    struct Node* pred = predecessor(node_pred);
                    if (pred) {
                        printf("Predecessor of %d is %d\n", value, pred->data);
                    } else {
                        printf("No predecessor for %d\n", value);
                    }
                } else {
                    printf("Node %d not found\n", value);
                }
                break;

            case 7:
                printf("Enter node value to find successor: ");
                scanf("%d", &value);
                struct Node* node_succ = search(root, value);
                if (node_succ) {
                    struct Node* succ = successor(node_succ);
                    if (succ) {
                        printf("Successor of %d is %d\n", value, succ->data);
                    } else {
                        printf("No successor for %d\n", value);
                    }
                } else {
                    printf("Node %d not found\n", value);
                }
                break;

            case 8:
                printf("Tree height: %zu\n", height(root));
                break;

            case 9:
                if (root) {
                    printf("Root balance factor: %d\n", balance_factor(root));
                } else {
                    printf("Tree is empty\n");
                }
                break;

            case 10:
                printf("Inorder traversal: ");
                inorder_trav(root);
                printf("\n");
                break;

            case 11:
                printf("Preorder traversal: ");
                preorder_trav(root);
                printf("\n");
                break;

            case 12:
                printf("Postorder traversal: ");
                postorder_trav(root);
                printf("\n");
                break;

            case 13:
                printf("How many nodes to insert? ");
                int count;
                scanf("%d", &count);
                printf("Enter %d values separated by spaces: ", count);
                for (int i = 0; i < count; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                printf("Inserted %d nodes\n", count);
                break;

            case 14:
                printf("\nASCII Tree:\n");
                print_tree(root);
                break;

            case 0:
                printf("Exiting...\n");
                running = false;
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}
