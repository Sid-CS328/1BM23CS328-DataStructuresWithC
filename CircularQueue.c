// Circular Queue Program

#include <stdio.h>
#include <stdlib.h>


#define MAX 5


typedef struct{
    int items[MAX];
    int front;
    int rear;
}CircularQueue;


void initQueue(CircularQueue *q){
    q -> front = -1;
    q -> rear = -1;
}


int isFull(CircularQueue *q){
    return((q -> front) == ((q -> rear + 1) % MAX));
}

int isEmpty(CircularQueue *q){
    return(q -> front == -1);
}



void enqueue(CircularQueue *q, int value){
    if(isFull(q)){
        printf("Queue is Full! \n");
        return;
    }

    if(isEmpty(q)){
        q -> front = 0;
    }

    q -> rear = (q -> rear + 1) % MAX;
    q -> items[q -> rear] = value;
    printf("Inserted %d into the queue. \n", value);
}



void dequeue(CircularQueue *q){
    if(isEmpty(q)){
        printf("Queue is Empty! \n");
        return;
    }

    int deletedValue = q -> items[q -> front];

    printf("Deleted %d from the queue. \n", deletedValue);

    if(q -> front == q -> rear){
        q -> front = -1;
        q -> rear = -1;
    }
    else{
        q -> front = (q -> front + 1) % MAX;
    }
}




void display(CircularQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty! \n");
        return;
    }

    printf("Queue Elements: ");

    for(int i = q -> front; i != q -> rear; i = (i + 1) % MAX){
        printf("%d, ", q -> items[i]);
    }

    printf("%d \n", q -> items[q -> rear]);
}




int main(){
    CircularQueue queue;
    initQueue(&queue);

    int choice, value;

    do{
        printf("\n Circular Queue Operations: \n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                dequeue(&queue);
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting \n");
                break;

            default:
                printf("Invalid choice! \n");
        }
    } while(choice != 4);

    return 0;
}