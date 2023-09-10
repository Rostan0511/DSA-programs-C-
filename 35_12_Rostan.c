#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the queue
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Function to initialize an empty queue
void initialize(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->data[queue->rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int value = queue->data[queue->front];
        if (queue->front == queue->rear) {
            // Queue has only one element, reset it to empty
            initialize(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return value;
    }
}

// Function to display the elements of the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        while (1) {
            printf("%d ", queue->data[i]);
            if (i == queue->rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    int dequeued = dequeue(&queue);
    if (dequeued != -1) {
        printf("Dequeued element: %d\n", dequeued);
    }

    display(&queue);

    return 0;
}
