#include <stdio.h>
#include <stdlib.h>

// Structure definition of a node representing a term in a polynomial
struct node {
    int coeff;          // Coefficient of the term
    int degree;         // Degree of the term
    struct node *before;  // Pointer to the previous (before) node in the list
    struct node *after;   // Pointer to the next (after) node in the list
};

void printList(struct node*);
void LIST_APPEND(struct node**, int, int);      // Inserting a new last element.
struct node *createNode(int, int);

// printing the elements of a linked list representing a polynomial

void PrintList(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    else {
        printf("List elements:\n");
    }
    
    while (head != NULL) {
        printf("%d x^%d ", head->coeff, head->degree);
        head = head->after;
    }
    printf("\n");
}

// Creating a new node with given coefficient and degree
struct node *CreateNode(int coeff, int degree) {
    struct node *Newnode = (struct node *)malloc(1*sizeof(struct node));
    Newnode->coeff = coeff;
    Newnode->degree = degree;
    Newnode->before = NULL;
    Newnode->after = NULL;
    return Newnode;
}

// Append a new node to the end of a linked list
void AppendNode(struct node **head, int coeff, int degree) {
    struct node *Newnode = CreateNode(coeff, degree);
    
    // If the list is empty, declare the new node as the head
    if (*head == NULL) {
        *head = Newnode;
        return;
    }
    
    // Traversing the list to find the last node
    struct node *temp = *head;
    while (temp->after != NULL) {
        temp = temp->after;
    }
    
    // Append the new node to the end of the list
    temp->after = Newnode;
    Newnode->before = temp;
}

// Function to add two polynomials represented by linked lists
void AddPolynomials(struct node *p1, struct node *p2, struct node **result) {
    // Traverse both polynomials until one of them reaches the end
    while (p1 && p2) {
        if (p1->degree == p2->degree)
		 {
            AppendNode(result, p1->coeff + p2->coeff, p1->degree); // If the degrees match, add the coefficients and append to result
            p1 = p1->after;
            p2 = p2->after;
        } else if (p1->degree > p2->degree) 
		{
            AppendNode(result, p1->coeff, p1->degree);  // If degree of p1 is greater, append p1's term to result
            p1 = p1->after;
        } else 
		{
            AppendNode(result, p2->coeff, p2->degree);  // If degree of p2 is greater, append p2's term to result
            p2 = p2->after;
        }
    }

    // Append  if any remaining terms from p1 and p2 to result
    while (p1)
	 {
        AppendNode(result, p1->coeff, p1->degree);
        p1 = p1->after;
    }

    while (p2) 
	{
        AppendNode(result, p2->coeff, p2->degree);
        p2 = p2->after;
    }
}

// Main function to test the polynomial addition
    
   int main()
{
    // Create and display polynomial P1
    struct node *p_head1 = NULL;
    AppendNode(&p_head1, 1, 4);
    AppendNode(&p_head1, 2, 5);
    AppendNode(&p_head1, 3, 6);
    
    printf("Polynomial P1:\n");
    PrintList(p_head1);

    // Create and display polynomial P2
    struct node *p_head2 = NULL;
    AppendNode(&p_head2, 6, 3);
    AppendNode(&p_head2, 5, 2);
    AppendNode(&p_head2, 4, 1);

    printf("Polynomial P2:\n");
    PrintList(p_head2);

    // Add P1 and P2
    struct node *result = NULL;
    AddPolynomials(p_head1, p_head2, &result);

    // Display the result polynomial
    printf("Result of P1 + P2:\n");
    PrintList(result);
    return 0;
}


    

