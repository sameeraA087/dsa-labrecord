#include <stdio.h>
#define MAX 100
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->front == -1;
}
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;  // Indicate error
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset after dequeue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Front element is %d\n", peek(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    if (isEmpty(&q)) {
        printf("Queue is empty now\n");
    } else {
        printf("Queue is not empty\n");
    }
    return 0;
}

