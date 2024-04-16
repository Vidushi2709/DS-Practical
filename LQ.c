#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    } else if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    int removedItem;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else if (q->front == q->rear) {
        removedItem = q->items[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        removedItem = q->items[q->front];
        q->front++;
    }
    return removedItem;
}

// Function to display the elements of the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    displayQueue(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    displayQueue(&q);

    return 0;
}
