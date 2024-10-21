// Program for Queue Implementation using Arrays


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Queue{
    int items[SIZE];
    int front;
    int rear;
} Queue;



// Create Queue
Queue* createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));

    q -> front = -1;
    q -> rear = -1;

    return q;
}



int isEmpty(Queue *q){
    return (q -> front == -1);
}

int isFull(Queue *q){
    return ((q -> rear + 1) % SIZE == q -> front);
}




// Insert Elements into Queue
void insert(Queue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow! \n");
    }

    else{
        if(isEmpty(q)){
            q -> front = 0;
        }

        q -> rear = (q -> rear + 1);
        q -> items[q -> rear] = value;

        printf("Inserted %d into Queue. \n", value);
    }
}





//Dequeue or Delete the Elements
void delete(Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow! \n");
    }
    else{
        int removed_value = q -> items[q -> front];

        if(q -> front == q -> rear){                        //If the Queue has only 1 element
            q -> front = -1;
            q -> rear = -1;
        }
        else{
            q -> front = (q -> front + 1);
        }

        printf("Deleted %d from Queue. \n", removed_value);
    }
}






// Display the Queue
void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty. \n");
    }
    else{
        int i = q -> front;
        
        printf("Queue elements: ");

        while(1){
            printf("%d, ", q -> items[i]);

            if(i == q -> rear){
                break;
            }

            i = (i + 1);
        }

        printf("\n");
    }
}






// Main function
int main(){
    Queue *q = createQueue();
    int choice, value;

    while(1){
        printf(" 1. Insert \n 2. Delete \n 3. Display \n 4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(q, value);
                break;

            case 2:
                delete(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                free(q);
                return 0;

            default:
                printf("Invalid Choice \n");
        }
    }

    return 0;
}