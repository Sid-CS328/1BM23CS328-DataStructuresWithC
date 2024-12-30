#include <stdio.h>
#include <stdlib.h>

#define MAX 5  


struct Stack {
    int arr[MAX];
    int top;
};


void initializeStack(struct Stack *s) {
    s->top = -1;
}


int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}


int isEmpty(struct Stack *s) {
    return s->top == -1;
}


void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } 
    else {
        s->top++;
        s->arr[s->top] = value;
        printf("%d pushed to stack.\n", value);
    }
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } 
    else {
        int poppedValue = s->arr[s->top];
        s->top--;
        return poppedValue;
    }
}


void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to display.\n");
    } 
    else {
        printf("Stack contents: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                
                display(&stack);
                break;
            case 4:
                
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
