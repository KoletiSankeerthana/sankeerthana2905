
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node
{
  int key;
  struct node *next;
};

// Global head pointer
struct node *L_head = NULL;

// Function prototypes
void printList();
void LIST_PREPEND(int);
void LIST_APPEND(int);
void LIST_INSERT(int, int);
void LIST_DELETE(int);
struct node *LIST_SEARCH(int);
struct node *createNode(int);

int main(void)
{
  char option = '\0';

  // Menu display
  printf("------------------------\n");
  printf("---Singly linked list---\n");
  printf("Show: S\n");
  printf("LIST-PREPEND: 1\n");
  printf("LIST-APPEND: 2\n");
  printf("LIST-INSERT: 3\n");
  printf("LIST-DELETE: 4\n");
  printf("EXIT: E\n");
  printf("------------------------\n");

  // Menu loop
  while (1)
  {
    printf("Enter your option: ");
    scanf(" %c", &option);

    switch (option)
    {
    case 'S':
      printf("Displaying the list\n\n");
      printList();
      break;

    case '1':
      printf("Enter the element to prepend the list: ");
      int x = 0;
      scanf("%d", &x);
      LIST_PREPEND(x);
      break;

    case '2':
      printf("Enter the element to append the list: ");
      x = 0;
      scanf("%d", &x);
      LIST_APPEND(x);
      break;

    case '3':
      printf("Enter the value after:");
      int y = 0;
      scanf("%d", &y);
      x = 0;
      printf("Enter the new value to insert: ");
      scanf("%d", &x);
      LIST_INSERT(x, y);
      break;

    case '4':
      printf("Enter the value to delete:");
      y = 0;
      scanf("%d", &y);
      LIST_DELETE(y);
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

// Function to print the list
void printList()
{
  if (L_head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    printf("List elements:\n");
    struct node *tmpHead = L_head;

    while (tmpHead != NULL)
    {
      printf("[%p]-->%d --> %p\n",
             tmpHead, tmpHead->key,tmpHead->next);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }
  return;
}

// Function to create a new node
struct node *createNode(int x)
{
  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->key = x;
  newNode->next = NULL;

  return newNode;
}

// Function to prepend an element to the list
void LIST_PREPEND(int x)
{
  struct node *newNode = createNode(x);
  newNode->next = L_head; 
  L_head = newNode; 
  printf("First element: %d\n", L_head->key);
}

// Function to append an element to the list
void LIST_APPEND(int x)
{
  struct node *newNode = createNode(x);

  if (L_head == NULL)
  {
    L_head = newNode;
    return;
  }

  struct node *lastNode = L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

}

// Function to insert an element after a given value
void LIST_INSERT(int x, int y)
{
  struct node *yNode = LIST_SEARCH(y);

  if (yNode == NULL)
  {
    printf("The value %d does not exist in list\n", y);
    return;
  }

  struct node *newNode = createNode(x);

  /* Update prev/next pointer of new node. */
  newNode->next = yNode->next;

  yNode->next = newNode;

  return;
  
}

// Function to search for a node with a given value
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

// Function to delete a node with a given value
void LIST_DELETE(int y)
{
  
  struct node *prevNode=NULL;
  struct node *presentNode=L_head;
  
  while(presentNode!=NULL&&presentNode->key!=y)
  {
    prevNode = presentNode;
    presentNode = presentNode->next;
  }
  // if the value is not found
  if (presentNode == NULL)
  {
    printf("the value %d does not exist\n",y);
    return;
  }
  //if the node to be deleted is the head
  if(prevNode != NULL )
  {
    prevNode->next=presentNode->next;
}
else
{
	L_head=presentNode->next;
	
}
free(presentNode);
return;
}

