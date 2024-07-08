#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
    int key;
    struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */
void PrintList();
struct node* LIST_PREPEND(int);     // Inserting a new first element.
struct node* LIST_APPEND(int);      // Inserting a new last element.
struct node* LIST_INSERT(int, int); // inserts x next to y.
void LIST_DELETE(int);      // Find the node containing value and remove the node.
struct node *LIST_SEARCH(int); //  Find the node containing the data.
struct node *createNode(int);  // Creates a new node and initialize the key.

int main(void)
{
    char option = '\0';

    printf("------------------------\n");
    printf("---Singly Linked List---\n");
    printf("Show: S\n");
    printf("LIST-PREPEND: 1\n");
    printf("LIST-APPEND: 2\n");
    printf("LIST-INSERT: 3\n");
    printf("LIST-DELETE: 4\n");
    printf("EXIT: E\n");
    printf("------------------------\n");

    while (1)
    {
        printf("Enter your option: ");
        scanf(" %c", &option);

        int x = 0, y = 0;  // Declaring the variables to avoid redeclaration

        switch (option)
        {
        case 'S':
            printf("Displaying the list\n\n");
            PrintList();
            break;

        case '1':
            printf("Enter the element to prepend the list: ");
            scanf("%d", &x);
            struct node *prependNode = LIST_PREPEND(x);
            printf("Memory address of the new node: %p\n", (void*)prependNode);
            break;

        case '2':
            printf("Enter the element to append the list: ");
            scanf("%d", &x);
            struct node *appendNode = LIST_APPEND(x);
            printf("Memory address of the new node: %p\n", (void*)appendNode);
            break;

        case '3':
            printf("Enter the value after:");
            scanf("%d", &y);

            printf("Enter the new value to insert: ");
            scanf("%d", &x);

            struct node *insertNode = LIST_INSERT(x, y); // insert x next to y
            if(insertNode)
                printf("Memory address of the new node: %p\n", (void*)insertNode);
            break;

        case '4':
            printf("Enter the value to delete:");
            scanf("%d", &y);
            LIST_DELETE(y); // Find the node containing y and delete it.
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

void PrintList()
{
    if (L_head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List elements and memory addresses:\n");
        struct node *tmpHead = L_head;

        while (tmpHead != NULL)
        {
            printf("Key: %d, Address: %p", tmpHead->key, (void*)tmpHead);
            
            if(tmpHead->next != NULL)
            {
                printf(", Next Address: %p", (void*)tmpHead->next);
            }
            
            printf("\n");
            tmpHead = tmpHead->next;
        }
    }
}

struct node *createNode(int x)
{
    struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->key = x;
    newNode->next = NULL;

    return newNode;
}

struct node* LIST_PREPEND(int x)
{
    struct node *newNode = createNode(x);
    newNode->next = L_head;
    L_head = newNode;

    return newNode;
}

struct node* LIST_APPEND(int x)
{
    struct node *newNode = createNode(x);

    if (L_head == NULL)
    {
        L_head = newNode;
        return newNode;
    }

    struct node *lastNode = L_head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    return newNode;
}

struct node* LIST_INSERT(int x, int y)
{
    struct node *yNode = LIST_SEARCH(y);

    if (yNode == NULL)
    {
        printf("The value %d does not exist in list\n", y);
        return NULL;
    }

    struct node *newNode = createNode(x);
    newNode->next = yNode->next;
    yNode->next = newNode;
    return newNode;
}

struct node *LIST_SEARCH(int y)
{
    struct node *yNode = L_head;

    if (L_head == NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
    else
    {
        while (yNode != NULL && yNode->key != y)
        {
            yNode = yNode->next;
        }

        return yNode;
    }
}

void LIST_DELETE(int y)
{
    struct node *yNode = LIST_SEARCH(y);

    if (yNode == NULL)
    {
        printf("The value %d does not exist\n", y);
        return;
    }

    if (yNode == L_head)
    {
        L_head = yNode->next;
        free(yNode);
        return;
    }

    struct node *prevNode = L_head;
    while (prevNode->next != yNode)
    {
        prevNode = prevNode->next;
    }

    prevNode->next = yNode->next;
    free(yNode);
}

