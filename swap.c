#include <stdio.h>

void swap(int, int);

int main() {
    int x = 5, y = 10;
    printf("Before swap x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After swap x=%d, y=%d\n", x, y);
    return 0;
}

void swap(int a, int b) {
    int temp;
    temp = b;
    b = a;
    a = temp;
}

