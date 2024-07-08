Skip to content
Sign in
vidhyakshayakannan
/
Data-Structures-and-Algorithms
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Commit
Added files (Assignment 1)
 main
= committed 12 hours ago
1 parent 2dedd8b
commit e4981fd
Showing 7 changed files with 651 additions and 0 deletions.
 130 changes: 130 additions & 0 deletions130  
Assignment1/DLL_Polynomial.c
@@ -0,0 +1,130 @@
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int coeff;
  int degree;
  struct node *prev;
  struct node *next;
};

/* List operations */
void printList(struct node *);
void LIST_APPEND(struct node **, int, int); // Inserting a new last element.
void addPolynomials(struct node *, struct node *, struct node **);
struct node *createNode(int, int); // Creates a new node and initialize the key.

int main(void)
{
  struct node *p_head1 = NULL;
  LIST_APPEND(&p_head1, 5, 3);
  LIST_APPEND(&p_head1, 4, 2);
  LIST_APPEND(&p_head1, 6, 1);

  printf("Polynomial P1:\n");
  printList(p_head1);

  struct node *p_head2 = NULL;
  LIST_APPEND(&p_head2, 6, 5);
  LIST_APPEND(&p_head2, 3, 2);
  LIST_APPEND(&p_head2, 4, 1);

  printf("Polynomial P2:\n");
  printList(p_head2);

  struct node *result = NULL;
  addPolynomials(p_head1, p_head2, &result);

  printf("Result of polynomial addition (P3):\n");
  printList(result);

  return 0;
}

void printList(struct node *L_head)
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
      printf("%dx^%d ", tmpHead->coeff, tmpHead->degree);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }
}

struct node *createNode(int coeff, int degree)
{
  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->coeff = coeff;
  newNode->degree = degree;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void LIST_APPEND(struct node **L_head, int coeff, int degree)
{
  struct node *newNode = createNode(coeff, degree);

  if (*L_head == NULL)
  {
    *L_head = newNode;
    return;
  }

  struct node *lastNode = *L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->prev = lastNode;
}

void addPolynomials(struct node *p1, struct node *p2, struct node **result)
{
  while (p1 != NULL && p2 != NULL)
  {
    if (p1->degree == p2->degree)
    {
      LIST_APPEND(result, p1->coeff + p2->coeff, p1->degree);
      p1 = p1->next;
      p2 = p2->next;
    }
    else if (p1->degree > p2->degree)
    {
      LIST_APPEND(result, p1->coeff, p1->degree);
      p1 = p1->next;
    }
    else
    {
      LIST_APPEND(result, p2->coeff, p2->degree);
      p2 = p2->next;
    }
  }

  while (p1 != NULL)
  {
    LIST_APPEND(result, p1->coeff, p1->degree);
    p1 = p1->next;
  }

  while (p2 != NULL)
  {
    LIST_APPEND(result, p2->coeff, p2->degree);
    p2 = p2->next;
  }
}
 147 changes: 147 additions & 0 deletions147  
Assignment1/InfixPostfix.c
@@ -0,0 +1,147 @@
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Global Variable Declarations */
struct node
{
  char data;
  struct node *prev;
  struct node *next;
};

/* Stack operations */
void push(struct node **top, char data);
char pop(struct node **top);
char peek(struct node *top);
bool is_empty(struct node *top);

/* Infix to Postfix conversion */
void infix_to_postfix(char *infix, char *postfix);

int precedence(char op);

int main(void)
{
  char infix[100], postfix[100];

  printf("Enter infix expression: ");
  scanf("%s", infix);

  infix_to_postfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}

void infix_to_postfix(char *infix, char *postfix)
{
  struct node *stack = NULL; // Stack to hold operators
  int i = 0, j = 0;

  while (infix[i] != '\0')
  {
    if (isalnum(infix[i]))
    {
      postfix[j++] = infix[i++];
    }
    else if (infix[i] == '(')
    {
      push(&stack, infix[i]);
      i++;
    }
    else if (infix[i] == ')')
    {
      while (!is_empty(stack) && peek(stack) != '(')
      {
        postfix[j++] = pop(&stack);
      }
      pop(&stack); // Discard the '('
      i++;
    }
    else
    {
      while (!is_empty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
      {
        postfix[j++] = pop(&stack);
      }
      push(&stack, infix[i]);
      i++;
    }
  }

  while (!is_empty(stack))
  {
    postfix[j++] = pop(&stack);
  }

  postfix[j] = '\0'; // Null-terminate the postfix string
}

void push(struct node **top, char data)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *top;

  if (*top != NULL)
  {
    (*top)->prev = newNode;
  }

  *top = newNode;
}

char pop(struct node **top)
{
  if (*top == NULL)
  {
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
  }

  struct node *temp = *top;
  char data = temp->data;
  *top = (*top)->next;

  if (*top != NULL)
  {
    (*top)->prev = NULL;
  }

  free(temp);
  return data;
}

char peek(struct node *top)
{
  if (top == NULL)
  {
    printf("Stack is empty!\n");
    exit(EXIT_FAILURE);
  }
  return top->data;
}

bool is_empty(struct node *top)
{
  return top == NULL;
}

int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return 0;
  }
}
 Binary file addedBIN +33.1 KB 
Assignment1/QueueLinkedList
Binary file not shown.
 145 changes: 145 additions & 0 deletions145  
Assignment1/QueueLinkedList.c
@@ -0,0 +1,145 @@
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */

struct node
{
    int data;
    struct node *next;
};

struct node *Q_head = NULL; // Pointer to the front element
struct node *Q_tail = NULL; // Pointer to the rear element

/* Queue operations */
void display();
void ENQUEUE(int);
void DEQUEUE();
void PEEK();

int isQ_EMPTY();

int main(void)
{
    int x = 0;
    char option = '\0';

    printf("-----------------\n");
    printf("---QUEUE  Menu---\n");
    printf("Show: S\n");
    printf("ENQUEUE: I\n");
    printf("DEQUEUE: D\n");
    printf("PEEK: P\n");
    printf("EXIT: E\n");
    printf("-----------------\n");

    while (1)
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'S':
            printf("Displaying Queue\n\n");
            display();
            break;

        case 'I':
            printf("Enter element to insert: ");
            scanf("%d", &x);
            ENQUEUE(x);
            break;

        case 'D':
            DEQUEUE();
            break;

        case 'P':
            PEEK();
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

void display()
{
    if (isQ_EMPTY())
    {
        printf("The queue is empty. \n");
    }
    else
    {
        struct node *current = Q_head;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void ENQUEUE(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (Q_tail == NULL)
    {
        Q_head = newNode;
        Q_tail = newNode;
    }
    else
    {
        Q_tail->next = newNode;
        Q_tail = newNode;
    }
}

void DEQUEUE()
{
    if (isQ_EMPTY())
    {
        printf("The queue is empty. UNDERFLOW. \n");
        return;
    }

    struct node *temp = Q_head;
    printf("Deleted: %d\n", temp->data);
    Q_head = Q_head->next;
    free(temp);

    if (Q_head == NULL)
    {
        Q_tail = NULL;
    }
}

void PEEK()
{
    if (isQ_EMPTY())
    {
        printf("The queue is empty. UNDERFLOW. \n");
        return;
    }

    printf("The next value which will be deleted is %d: ", Q_head->data);
}

int isQ_EMPTY()
{
    return Q_head == NULL;
}
 Binary file addedBIN +33.2 KB 
Assignment1/SinglyLinkedList
Binary file not shown.
 229 changes: 229 additions & 0 deletions229  
Assignment1/SinglyLinkedList.c
@@ -0,0 +1,229 @@
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
void printList();
void LIST_PREPEND(int);     // Inserting a new first element.
void LIST_APPEND(int);      // Inserting a new last element.
void LIST_INSERT(int, int); // inserts x next to y.
void LIST_DELETE(int);      // Find the node containing value and remove the node.
struct node *LIST_SEARCH(int); // Find the node containing the data.
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

      LIST_INSERT(x, y); // insert x next to y

      break;

    case '4':
      printf("Enter the value to delete:");
      y = 0;
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
  struct node *prevNode = NULL;
  struct node *currentNode = L_head;

  while (currentNode != NULL && currentNode->key != y)
  {
    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  if (currentNode == NULL)
  {
    printf("The value %d does not exist\n", y);
    return;
  }

  if (prevNode != NULL)
  {
    prevNode->next = currentNode->next;
  }
  else
  {
    L_head = currentNode->next;
  }

  free(currentNode);

  return;
}
 Binary file addedBIN +6 KB 
Lecture 2/.DS_Store
Binary file not shown.
0 comments on commit e4981fd
Please sign in to comment.
Footer
© 2024 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact
Manage cookies
Do not share my personal information
Added files (Assignment 1) · vidhyakshayakannan/Data-Structures-and-Algorithms@e4981fd · GitHub
