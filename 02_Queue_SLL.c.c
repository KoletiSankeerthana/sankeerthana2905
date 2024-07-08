#include <stdio.h>
#include <stdlib.h>

#define Q_Size 5 /* Declaration of Global Variable */

typedef struct Node //Defining the structure for a Node in the Queue
{
    int data;          // Stored Data in the Node
    struct Node* link; // Pointer to the next Node in the Queue
} Node;

struct Node* head = NULL; // Pointer to the head of the Queue
struct Node* tail = NULL; // Pointer to the tail of the Queue

// Function Declarations
void Display();
void Enqueue(int);
void Dequeue();
void Peek();
int isQ_Empty();
int Queue_Size();

int main(void)
{
    int x = 0;
    char option = '\0';

    // Display the Menu for the Queue operations
    printf("-----------------\n");
    printf("---QUEUE  Menu---\n");
    printf("Show: S\n");
    printf("ENQUEUE: I\n");
    printf("DEQUEUE: D\n");
    printf("PEEK: P\n");
    printf("EXIT: E\n");
    printf("-----------------\n");

    // Main loop to execute Queue operations
    while (1)
    {
        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'S':
            printf("Displaying Queue\n\n");
            Display();
            break;

        case 'I':
            printf("Enter element to insert:");
            scanf("%d", &x);
            Enqueue(x);
            break;

        case 'D':
            Dequeue();
            break;

        case 'P':
            Peek();
            break;

        case 'E':
            printf("Exit\n\n");
            exit(0);

        default:
            printf("Enter correct option\n\n");
        }
    }

    return 0;
}

// Function to get the current size of the Queue
int Queue_Size()
{
    int size = 0;
    struct Node* temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->link;
    }
    return size;
}

// Function to display the elements of the Queue
void Display()
{
    struct Node* temp;
    if (isQ_Empty())
    {
        printf("\nQueue is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

// Function to insert an element at the tail of the Queue (Enqueue)
void Enqueue(int x)
{
    if (Queue_Size() >= Q_Size)
    {
        printf("\nQueue is full. Cannot enqueue more elements.\n");
        return;
    }

    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    
    newnode->data = x;
    newnode->link = NULL;

    if (head == NULL && tail == NULL)
    {
        
        head = tail = newnode; // If the Queue is empty, set both head and tail to the new node
    }
    else
    {
        
        tail->link = newnode;  // If not, add the new node at the tail of the Queue
        tail = newnode;
    }
    printf("\n");
}

// Function to remove an element from the head of the Queue (Dequeue)
void Dequeue()
{
    if (isQ_Empty())
    {
        printf("\nQueue is empty");
        return;
    }

    struct Node* temp;
    temp = head;
    printf("\n%d", temp->data);
    head = head->link;
    free(temp);
    printf("\n");
}

// Function to display the element at the head of the Queue (Peek)
void Peek()
{
    if (isQ_Empty())
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("%d", head->data);
    }
    printf("\n");
}

// Function to check if the Queue is empty or not
int isQ_Empty()
{
    return head == NULL;
}

