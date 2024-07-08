#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue(int value) {
    if (rear1 == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front1 == -1) {
        front1 = 0;
    }
    rear1++;
    queue[rear1] = value;
}

int dequeue() {
    if (front1 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[front1];
    if (front1 == rear1) {
        front1 = rear1 = -1;
    } else {
        front1++;
    }
    return value;
}

void push(int value) {
    enqueue(value);
    while (front2 != -1) {
        enqueue(dequeue());
    }
    int *temp = &front1;
    front1 = front2;
    front2 = *temp;
}

int pop() {
    if (front1 == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue();
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6); // This should indicate that the stack is full

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop()); // This should indicate that the stack is empty

    return 0;
}

