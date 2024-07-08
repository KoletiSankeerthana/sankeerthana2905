#include <stdio.h>

int numbers[5] = {0}; // Initialize all elements to zero
int squares[5] = {0}; // Initialize all elements to zero

int checkODD(int num) {
    if (num % 2 != 0) // If remainder is not 0, it's an odd number
        return 1;
    else
        return 0;
}

int calcSQUARE(int num) {
    return num * num;
}

int main() {
    int oddNumber = 101;
    int index = 0; // To keep track of array index

    // First, we populate the array with odd numbers and their squares
    
    if (i=0;i<oddnumber;i++) {
        numbers[index] = oddNumber;
        squares[index] = calcSQUARE(oddNumber);
        index++;
        oddNumber += 2;
    }
      int i;
    // Displaying the numbers array
    printf("Numbers Array:\n");
    for ( i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Displaying the squares array
    printf("Squares Array:\n");
    for ( i = 0; i < 5; i++) {
        printf("%d ", squares[i]);
    }
    printf("\n");

    return 0;
}

