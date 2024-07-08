#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int key;
  struct node *next;
};

struct node *L_head = NULL; // Empty List

/* Declaration of List Operations */
void printList();
void LIST_PREPEND(int);     // Adding a new element in the first
void LIST_APPEND(int);      // Adding a new element in the last
void LIST_INSERT(int, int); // inserts x next to y.
void LIST_DELETE(int);      // Finds the node containing value and remove the node.
struct node *LIST_SEARCH(int); // Finds the node containing the data.
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
  
   int x=0,y=0; // Initializing x,y to 0 at once instead mentioning in every cases 
   
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
      scanf("%d", &x);
      LIST_PREPEND(x);

      break;

    case '2':
      printf("Enter the element to append the list: ");
      scanf("%d", &x);
      LIST_APPEND(x);

      break;

    case '3':
      printf("Enter the value after:");
      scanf("%d", &y);

      printf("Enter the new value to insert: ");
      scanf("%d", &x);

      LIST_INSERT(x, y); // insert x next to y

      break;

    case '4':
      printf("Enter the value to delete:");
      scanf("%d", &y);

      LIST_DELETE(y); // Finds the node containing y and delete it.

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
      printf("[%p] --> %d --> %p\n",
             tmpHead, tmpHead->key, tmpHead->next);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

struct node *createNode(int x)
{
  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->key = x;
  newNode->next = NULL;

  return newNode;
}

void LIST_PREPEND(int x)
{
  struct node *newNode = createNode(x);

  newNode->next = L_head;
  L_head = newNode;

  printf("First element: %d\n", L_head->key);
}

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

  return;
}

void LIST_INSERT(int x, int y)
{
  struct node *yNode = LIST_SEARCH(y);

  if (yNode == NULL)
  {
    printf("The value %d do not exist in list\n", y);
    return;
  }

  struct node *newNode = createNode(x);
  newNode->next = yNode->next;
  yNode->next = newNode;

  return;
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
  struct node *beforeNode = NULL;
  struct node *presentNode = L_head;

  while (presentNode != NULL && presentNode->key != y)
  {
    beforeNode = presentNode;
    presentNode = presentNode->next;
  }

  if (presentNode == NULL)
  {
    printf("The value %d does not exist\n", y);
    return;
  }

  if (beforeNode != NULL)
  {
    beforeNode->next = presentNode->next;
  }
  else
  {
    L_head = presentNode->next;
  }

  free(presentNode);

  return;
}
