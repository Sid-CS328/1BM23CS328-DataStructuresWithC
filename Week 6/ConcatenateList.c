#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
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


void sortLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty, cannot sort.\n");
        return;
    }

    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}


struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
    return head;
}


struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

 
    temp->next = head2;

    printf("Lists concatenated successfully.\n");
    return head1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Create first linked list\n");
        printf("2. Create second linked list\n");
        printf("3. Display first linked list\n");
        printf("4. Display second linked list\n");
        printf("5. Sort first linked list\n");
        printf("6. Reverse first linked list\n");
        printf("7. Concatenate two linked lists\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = createLinkedList();
                printf("First linked list created successfully!\n");
                break;
            case 2:
                head2 = createLinkedList();
                printf("Second linked list created successfully!\n");
                break;
            case 3:
                displayLinkedList(head1);
                break;
            case 4:
                displayLinkedList(head2);
                break;
            case 5:
                sortLinkedList(head1);
                break;
            case 6:
                head1 = reverseLinkedList(head1);
                break;
            case 7:
                head1 = concatenateLists(head1, head2);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
