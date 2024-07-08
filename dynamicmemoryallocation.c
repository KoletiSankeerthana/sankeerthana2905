#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intArray;

    // Using malloc
    int number = 3;
    intArray = (int *)malloc(number * sizeof(int));
    int i;
    // Populate and print array elements
    printf("Using malloc: ");
    for (i = 0; i < number; ++i) {
        intArray[i] = i + 1;
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Using calloc
    intArray = (int *)calloc(number, sizeof(int));

    // Populate and print array elements
    printf("Using calloc: ");
    for (i = 0; i < number; ++i) {
        intArray[i] = i + 1;
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Use realloc to accommodate 5 elements
    intArray = (int *)realloc(intArray, 5 * sizeof(int));

    // Populate and print the resized array elements
    printf("After realloc: ");
    for (i = 0; i < 5; ++i) {
        intArray[i] = i + 1;
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Free allocated memory
    free(intArray);

    return 0;
}

