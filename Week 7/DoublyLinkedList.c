#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void createList(struct Node** head) {
    *head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    printf("List created successfully.\n");
}


void insertLeft(struct Node** head, int targetValue, int data) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != targetValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found in the list.\n", targetValue);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode; 
    }
    temp->prev = newNode;

    printf("Node with value %d inserted to the left of node %d.\n", data, targetValue);
}


void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

   
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Node with value %d not found in the list.\n", value);
        return;
    }

    
    if (temp->prev == NULL && temp->next == NULL) {
        *head = NULL;
    }
    
    else if (temp->prev == NULL) {
        *head = temp->next;
        (*head)->prev = NULL;
    }
    
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted.\n", value);
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, targetValue;

    while (1) {
        printf("\nSelect operation:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert a new node to the left of a node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                printf("Enter the value of the node to insert before: ");
                scanf("%d", &targetValue);
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                insertLeft(&head, targetValue, data);
                break;
            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
