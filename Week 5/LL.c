// Singly Linked List



#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};



void createLL(struct Node** head, int n){
    struct Node* newNode, *temp;
    int value;

    for(int i = 0; i < n; i++){
        newNode = (struct Node*) malloc (sizeof(struct Node));

        if (newNode == NULL){
            printf("Memory allocation failed. \n");
            return;
        }

        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);

        newNode -> data = value;
        newNode -> next = NULL;

        if (*head == NULL){
            *head = newNode;
        }
        else{
            temp = *head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
}




void deleteF(struct Node** head){
    if(*head == NULL){
        printf("The list is empty. \n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head) -> next;

    free(temp);
    printf("First element deleted. \n");
}



void deleteL(struct Node** head){
    if(*head == NULL){
        printf("The list is already empty. \n");
        return;
    }

    struct Node* temp = *head, *prev = NULL;

    if(temp -> next == NULL){
        free(temp);
        *head = NULL;
        printf("Last element deleted. \n");
        return;
    }

    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = NULL;
    free(temp);
    printf("Last element deleted. \n");
}




void deleteS(struct Node** head, int value){
    if(*head == NULL){
        printf("The list is already empty. \n");
        return;
    }

    struct Node* temp = *head, *prev = NULL;

    if(temp != NULL && temp -> data == value){
        *head = temp -> next;
        free(temp);
        printf("Element %d deleted. \n", value);
        return;
    }

    while(temp != NULL && temp -> data != value){
        prev = temp;
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("Element %d not found. \n", value);
        return;
    }

    prev -> next = temp -> next;
    free(temp);
    printf("Element %d deleted. \n", value);
}




void display(struct Node* head){
    if(head == NULL){
        printf("The list is already empty. \n");
        return;
    }

    struct Node* temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
    
}





int main(){
    struct Node* head = NULL;
    int choice, value, n;

    do{
        printf("\nOperations: \n");
        printf("1. Create a Linked List \n");
        printf("2. Delete First Element \n");
        printf("3. Delete Last Element \n");
        printf("4. Delete Specified Element \n");
        printf("5. Display Linked List \n");
        printf("6. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice){
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createLL(&head, n);
                break;

            case 2:
                deleteF(&head);
                break;

            case 3:
                deleteL(&head);
                break;

            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                deleteS(&head, value);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting program. \n");
                break;

            default:
                printf("Invalid choice!");
        }
    } while(choice != 6);

    return 0;
}



