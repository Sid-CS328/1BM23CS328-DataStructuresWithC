#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data); 
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);    
        inorderTraversal(root->right);
    }
}


void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);   
        preorderTraversal(root->left); 
        preorderTraversal(root->right); 
    }
}


void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left); 
        postorderTraversal(root->right); 
        printf("%d ", root->data); 
    }
}


void displayTree(struct Node* root) {
    printf("\nIn-order traversal: ");
    inorderTraversal(root);

    printf("\nPre-order traversal: ");
    preorderTraversal(root);

    printf("\nPost-order traversal: ");
    postorderTraversal(root); 
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree (All Traversals)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data); 
                printf("Node inserted.\n");
                break;
            case 2:
                displayTree(root);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
