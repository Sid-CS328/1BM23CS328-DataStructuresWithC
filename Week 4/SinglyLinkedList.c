// Program to create a Singly Linked List

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* createLinkedList() {
    int data;
    struct Node *head = NULL, *temp = NULL;
    char choice;

    do {
        printf("Enter data for new node: ");
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode; 

        printf("Do you want to add another node (y/n)? ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');

    return head;
}


struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}


struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}


struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position! Insertion failed.\n");
        return head;
    }

    struct Node* newNode = createNode(data);


    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    int count = 1;

   
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

 
    if (temp == NULL) {
        printf("Position is greater than the length of the list.\n");
        free(newNode);
        return head;
    }


    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


void displayLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at first position\n");
        printf("3. Insert at any position\n");
        printf("4. Insert at end position\n");
        printf("5. Display linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createLinkedList();
                printf("Linked list created successfully!\n");
                break;
            case 2:
                printf("Enter data to insert at the first position: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                printf("Node inserted at the first position.\n");
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                printf("Node inserted at position %d.\n", position);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Node inserted at the end of the list.\n");
                break;
            case 5:
                displayLinkedList(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
