#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    int popped = pop(&stack);
    if (popped != -1) {
        printf("Popped element: %d\n", popped);
    }

    display(&stack);

    return 0;
}
