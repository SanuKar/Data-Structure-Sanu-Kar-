#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(int data) {
    struct Node* newNode = createNode(data);

    if (root == NULL) {
        root = newNode;
    } else {
        struct Node* current = root;
        struct Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(struct Node* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    int arr[] = {8, 10, 3, 1, 6, 14, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    int choice;

    do {
        printf("\nMenu\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inorderTraversal(root);
                break;
            case 2:
                preorderTraversal(root);
                break;
            case 3:
                postorderTraversal(root);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}