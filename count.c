#include <stdio.h>

int main() {
    int num;
    int count = 0;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Count the digits
    while (num != 0) {
        num /= 10;
        count++;
    }

    // Output
    printf("Number of digits: %d\n", count);

    return 0;
}
