
#include <stdio.h>

int main() {
    int num[5] = {0};
    int square[5]={0};
    int value = 101;
    int i;

    for (i = 0; i < 5; i++) 
	{
        if (value % 2 != 0)
        num[i] = value;
        value += 2;
        printf("\n %d is odd", num[i]);
    }

    for (i = 0; i < 5; i++) {
        square[i] = num[i] * num[i];
        printf("\n %d*%d=%d", num[i], num[i], square[i]);
    }
    return 0;
}

