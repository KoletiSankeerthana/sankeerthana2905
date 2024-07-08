#include <stdio.h>

int main()
{
    int n; // The size of the array
    printf("\n Enter the count of number you would like to process: ");
    scanf("%d", &n);

    int arr[n]; // Declare an integer array of size n

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Read integers from the user and store them in the array
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (arr[i] > arr[j])
                continue;
            else
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
        // scanf("%d", &arr[i]); // Read integers from the user and store them in the array
    }

    printf("You entered the following integers:\n");
    for (int i = 0; i < n ; i++)
    {
        printf("arr[%d]: %d \n", i, arr[i]); // Print the values stored in the array
    }

    return 0;
}
