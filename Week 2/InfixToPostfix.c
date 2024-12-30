// Infix to Postfix Program

#include <stdio.h>
#include <ctype.h>   
#include <stdlib.h>  

#define MAX 100  


struct Stack {
    char arr[MAX];
    int top;
};


void initStack(struct Stack* s) {
    s->top = -1;
}


int isEmpty(struct Stack* s) {
    return s->top == -1;
}


int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}


void push(struct Stack* s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->arr[++(s->top)] = c;
}


char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}


char peek(struct Stack* s) {
    if (isEmpty(s)) {
        return -1; 
    }
    return s->arr[s->top];
}


int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;  
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char currentChar;

    while ((currentChar = infix[i++]) != '\0') {
        
        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        }
        
        else if (currentChar == '(') {
            push(&s, currentChar);
        }
        
        else if (currentChar == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  
        }
        
        else if (isOperator(currentChar)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(currentChar)) {
                postfix[j++] = pop(&s);
            }
            push(&s, currentChar);
        }
    }

  
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; 
}


int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
