#include <stdio.h>
#include <math.h>

// Function to check if the input array is in ascending or descending order
int order(int arr[], int n) 
{
    int i;
    int ascending = 1;
    int descending = 1;

    for ( i = 1; i < n; i++) 
	{

        if (arr[i] > arr[i - 1]) {
            descending = 0;
        } else if (arr[i] < arr[i - 1]) {
            ascending = 0;
        }
    }

    return ascending || descending;
}

// Function to read and validate input values
int input(int Age[], int n)
 {
     int i; 
    for ( i = 0; i < n; i++)
	 {
        printf("Enter any integer between 1 to 125  ",i+1);
        scanf("%d", &Age[i]);

        if (Age[i] < 1 || Age[i] > 125) 
		{
            printf("Invalid:enter between 1 to 125.\n");
            return 0; // Return 0 to indicate an error
        }
    }
    return 1; // Return 1 to indicate successful input
}

// Function to calculate the minimum value in the array
int minimum(int Age[], int n) {
    int min = Age[0],i;
    for (i = 1; i < n; i++) {
        if (Age[i] < min) {
            min = Age[i];
        }
    }
    return min;
}

// Function to calculate the maximum value in the array
int maximum(int Age[], int n) {
    int max = Age[0],i;
    for ( i = 1; i < n; i++) {
        if (Age[i] > max) {
            max = Age[i];
        }
    }
    return max;
}

// Function to calculate the mean (average) of the array
float mean(int Age[], int n) {
    float sum = 0.0;
    int i;
    for ( i = 0; i < n; i++) {
        sum += Age[i];
    }
    return sum / n;
}

// Function to calculate the standard deviation of the array
float standarddeviation(int Age[], int n, float mean) {
    float variance = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        variance += pow(Age[i] - mean, 2);
    }
    return sqrt(variance / n);
}

// Function to calculate the second smallest value in the array
int secondsmallest(int Age[], int n) {
    int min = Age[0];
    int secondsmallest = Age[0],i;

    for (i = 1; i < n; i++) {
        if (Age[i] < min) {
            secondsmallest = min;
            min = Age[i];
        } else if (Age[i] < secondsmallest && Age[i] != min) {
            secondsmallest = Age[i];
        }
    }
    return secondsmallest;
}

// Function to calculate the second largest value in the array
int secondlargest(int Age[], int n) {
    int max = Age[0];
    int secondlargest = Age[0];
    int i;
    for (i = 1; i < n; i++) {
        if (Age[i] > max) {
            secondlargest = max;
            max = Age[i];
        } else if (Age[i] > secondlargest && Age[i] != max) {
            secondlargest = Age[i];
        }
    }
    return secondlargest;
}

int main() {
    int Age[10];
    int n = 10;

    // Read and validate input values
    if (input(Age, n) == 0)
	 {
        return 0; // Exit with an error code
    }

    // Check if the array is in ascending or descending order
    if (order(Age, n)) {
        printf("Error: The input numbers should not be in ascending or descending order.\n");
        return 1; // Exit with an error code
    }
    int min_val = minimum(Age, n);
    int max_val = maximum(Age, n);
    float mean_val = mean(Age, n);
    float std_dev = standarddeviation(Age, n, mean_val);
    int second_min = secondminimum(Age, n);
    int second_max = secondmaximum(Age, n);

    // Display the results
    printf("minimum: %d\n", min_val);
    printf("maximum: %d\n", max_val);
    printf("mean: %.2f\n", mean_val);
    printf("standarddeviation: %.2f\n", std_dev);
    printf("secondminimum: %d\n", second_min);
    printf("secondmaximum: %d\n", second_max);

    return 0;
}

