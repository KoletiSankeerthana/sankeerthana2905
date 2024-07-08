#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int array[MAX];
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = MAX;
    queue->front = queue->size = 0;
    queue->rear = MAX - 1;
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(Queue* queue) {
    return queue->size;
}

typedef struct {
    Queue* q1;
    Queue* q2;
} Stack;

// Function to create a stack using two queues
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Function to add an item to stack
void push(Stack* stack, int x) {
    if (isFull(stack->q1)) {
        printf("Stack overflow\n");
        return;
    }

    enqueue(stack->q2, x);

    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

// Function to remove an item from stack
void pop(Stack* stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack underflow\n");
        return;
    }
    dequeue(stack->q1);
}

// Function to get the top item of stack
int top(Stack* stack) {
    if (isEmpty(stack->q1)) {
        return -1;
    }
    return front(stack->q1);
}

// Function to get the size of stack
int stackSize(Stack* stack) {
    return size(stack->q1);
}

// Driver code
return 0;
}
