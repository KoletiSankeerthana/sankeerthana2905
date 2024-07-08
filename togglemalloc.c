#include <stdio.h>
#include <stdlib.h>

// Function to toggle upper-lower cases in-place
void toggleCases(char *str, int size) 
{
	int i;
    for ( i = 0; i < size && str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';  // Convert lowercase to uppercase
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';  // Convert uppercase to lowercase
        }
        // Ignore non-alphabetic characters
    }
}

int main() {
    // Create a dynamic char array
    char *pStr = (char *)malloc(32 * sizeof(char));

    if (pStr == NULL) {
        printf( "Memory allocation failed.\n");
    }
    else 
    {
    printf("Enter a string of up to 32 characters: ");
    scanf("%31s", pStr);

    // Toggle upper-lower cases in-place using the function
    toggleCases(pStr, 32);

    // Print the modified string
    printf("Modified string: %s\n", pStr);
}
    // Access contents of the dynamic array in various ways
    printf("\nAccessing contents in various ways:\n");
    int i;
    for ( i = 0; i < 32 && pStr[i] != '\0'; ++i) {
        printf("pStr[%d] = %c   *(pStr + %d) = %c   \n", i, pStr[i], i, *(pStr + i), *(pStr + i));
    }

    // Free the allocated memory
    free(pStr);

    return 0;
}

