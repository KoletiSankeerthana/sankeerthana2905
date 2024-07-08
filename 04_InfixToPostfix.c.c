#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
struct node  // Declaration of Global variable
{
  char data;
  struct node *before;
  struct node *after;
};

#define TRUE 1
#define FALSE 0

/* Stack operations */
void PUSH(struct node **head, char data);
char POP(struct node **head);
char PEEK(struct node *head);
int Is_Empty(struct node *head);

/* Infix to Postfix conversion */
void Infix_to_Postfix(char *Infix, char *Postfix);

int Order(char option);

int main(void)
{
  char Infix[30], Postfix[30];

  printf("Enter the Infix expression: ");
  scanf("%s", Infix);

  Infix_to_Postfix(Infix, Postfix);

  printf("The Postfix expression: %s\n", Postfix);

  return 0;
}

void Infix_to_Postfix(char *Infix, char *Postfix)
{
  struct node *stack = NULL;
  int l = 0, m= 0;

  while (Infix[l] != '\0')
  {
    if (isalnum(Infix[l]))
    {
      Postfix[m++] = Infix[l++];
    }
    else if (Infix[l] == '(')
    {
      PUSH(&stack, Infix[l]);
      l++;
    }
    else if (Infix[l] == ')')
    {
      while (!Is_Empty(stack) && PEEK(stack) != '(')
      {
        Postfix[m++] = POP(&stack);
      }
      POP(&stack);
      l++;
    }
    else
    {
      while (!Is_Empty(stack) && Order(Infix[l]) <= Order(PEEK(stack)))
      {
        Postfix[m++] = POP(&stack);
      }
      PUSH(&stack, Infix[l]);
      l++;
    }
  }

  while (!Is_Empty(stack))
  {
    Postfix[m++] = POP(&stack);
  }

  Postfix[m] = '\0'; 
}

void PUSH(struct node **head, char data)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->before = NULL;
  newNode->after = *head;

  if (*head != NULL)
  {
    (*head)->before = newNode;
  }

  *head = newNode;
}

char POP(struct node **head)
{
  if (*head == NULL)
  {
    printf("Stack is underflow!\n");
    exit(EXIT_FAILURE);
  }

  struct node *tempvar = *head;
  char data = tempvar->data;
  *head = (*head)->after;

  if (*head != NULL)
  {
    (*head)->before = NULL;
  }

  free(tempvar);
  return data;
}

char PEEK(struct node *head)
{
  if (head == NULL)
  {
    printf("Stack is empty!\n");
    exit(EXIT_FAILURE);
  }
  return head->data;
}

int Is_Empty(struct node *head)
{
  return head == NULL ? TRUE : FALSE;
}

int Order(char choice)
{
  switch (choice)
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

