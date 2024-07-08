#include <stdio.h>

int main() {
    long long int number;
    int position = 0; // Position of the current digit
    int consecutiveThrees = 0; // Counter for consecutive 3's

    // Input
    printf("Enter a positive number with at least 5 digits and at most 8 digits: ");
    scanf("%lld", &number);

    // Check if the input number is within the specified range
    if (number <= 0 || number < 10000 || number > 99999999) {
        printf("Error: Please enter a positive number with 5 to 8 digits.\n");
        return 1;
    }

    // Loop through the digits of the number
    while (number > 0) {
        int digit = number % 10;
        number /= 10;
        position++;

        if (digit == 3) {
            consecutiveThrees++; // Found a 3, increment the count
            if (consecutiveThrees == 3) {
                // Three consecutive 3's found, print the position
                printf("Three consecutive 3's found starting at position %d\n", position - 2);
                return 0;
            }
        } else {
            consecutiveThrees = 0; // Reset the count if the current digit is not 3
        }
    }

    // If no three consecutive 3's were found
    printf("No three consecutive 3's found in the number.\n");

    return 0;
}
