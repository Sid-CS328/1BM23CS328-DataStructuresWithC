// Program to create a Singly Linked List


#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


struct Node* createNode(int data){
    struct Node *newNode = (struct Node*) malloc (sizeof(newNode));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}



void insertBeginning(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
    printf("%d inserted at the Beginning \n", data);
}



void insertEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;

    printf("%d inserted at the End \n", data);
}




void display(struct Node *head){
    struct Node *temp = head;
    printf("\n");
    printf("Linked List: \n");
    while (temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
}




int main(){
    struct Node *head = NULL;
    struct Node *temp = head;

    int choice, value_data;


    do{
        printf("\n Linked List Operations: \n");
        printf("1. Insert at the Beginning \n");
        printf("2. Insert at the End \n");
        printf("3. Display the List \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice){
            case 1:
                //printf("%d \n", value_data);
                printf("Enter Value to insert:");
                scanf("&d", &value_data);

                //printf("%d \n", value_data);

                insertBeginning(&head, value_data);
                break;

            case 2:
                printf("Enter Value to insert:");
                scanf("&d", &value_data);
                insertEnd(&head, value_data);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting \n");
                break;

            default:
                printf("Invalid choice! \n");
        }
    } while(choice != 4);


    while(head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }


    return 0;
}




