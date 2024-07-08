#include <stdio.h>

int main() {
    // Declare a character array (string)
    char myString[20]; // This can hold up to 19 characters + '\0' (null terminator)

    // Initialize the character array with a string
    // Note: The '\0' at the end is automatically added to mark the end of the string.
    strcpy(myString, "Hello, World!");
    char targetChar = 'd' ;

    // Printing the entire string
    printf("String: %s\n", myString);

    int i=0;

    // Accessing and printing individual characters in the string
    printf("Individual characters:\n");
    for ( i = 0; myString[i] != '\0'; i++) {
        //printf("Character at index %d: %c\n", i, myString[i]);
        //printf("arr[%d]: %c\n", i, myString[i]);
        if (myString[i] == targetChar){
          printf ( "Target Char :%c is in position %d",targetChar, i);
          break;
        }
    }

    int temp = i-3;
    printf ( "\n ++the desired character:+++++++ %c", myString[temp]);
    return (0);
}
