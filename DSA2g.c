#include <stdio.h>

#define MAX_SIZE 5

int q1[MAX_SIZE];
int q2[MAX_SIZE];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

// Function to check if queue1 is empty
int isEmpty1() {
  return f1 == -1;
}

// Function to check if queue2 is empty
int isEmpty2() {
  return f2 == -1;
}

// Function to check if queue1 is full
int isFull1() {
  return r1 == MAX_SIZE - 1;
}

// Function to check if queue2 is full
int isFull2() {
  return r2 == MAX_SIZE - 1;
}

// Function to enqueue an element into queue1
void enqueue1(int data) {
  if (isFull1()) {
    printf("Queue1 Overflow\n");
    return;
  }
  if (f1 == -1) {
    f1 = 0;
  }
  q1[++r1] = data;
}

// Function to dequeue an element from queue1
int dequeue1() {
  if (isEmpty1()) {
    printf("Queue1 Underflow\n");
    return -1;
  }
  int data = q1[f1];
  if (f1 == r1) {
    f1 = r1 = -1;
  } else {
    f1++;
  }
  return data;
}

// Function to enqueue an element into queue2
void enqueue2(int data) {
  if (isFull2()) {
    printf("Queue2 Overflow\n");
    return;
  }
  if (f2 == -1) {
    f2 = 0;
  }
  q2[++r2] = data;
}

// Function to push an element onto stack
void push(int data) {
  // Enqueue x to q2
  if (isFull2()) {
    printf("Stack Overflow\n");
    return;
  }
  enqueue2(data);

  // Dequeue everything from q1 and enqueue to q2
  while (!isEmpty1()) {
    enqueue2(dequeue1());
  }

  // Swap the names of q1 and q2
  int temp[MAX_SIZE];
  int i;
  for (i = 0; i <= r2; i++) {
    temp[i] = q2[i];
  }
  f1 = 0;
  r1 = r2;
  for (i = 0; i <= r1; i++) {
    q1[i] = temp[i];
  }
  f2 = -1;
  r2 = -1;
}

// Function to pop an element from stack
int pop() {
  if (isEmpty1()) {
    printf("Stack Underflow\n");
    return -1;
  }
  return dequeue1();
}

int main() {
  push(10);
  push(20);
  push(30);

  printf("Popped element: %d\n", pop());

  return 0;
}

