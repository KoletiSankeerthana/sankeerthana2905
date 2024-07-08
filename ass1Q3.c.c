#include <stdio.h>
#include <math.h>

int Minimum(int Age[], int n) {
    int min = Age[0], i;
    for (i = 1; i < n; i++) {
        if (Age[i] < min) {
            min = Age[i];
        }
    }
    return min;
}

int Maximum(int Age[], int n) {
    int max = Age[0], i;
    for (i = 1; i < n; i++) {
        if (Age[i] > max) {
            max = Age[i];
        }
    }
    return max;
}

float Mean(int Age[], int n) {
    float sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sum += Age[i];
    }
    return sum / n;
}

float StandardDeviation(int Age[], int n, float mean) {
    float variance = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        variance += pow(Age[i] - mean, 2);
    }
    return sqrt(variance / n);
}

int SecondSmallest(int Age[], int n) {
    int min = Age[0];
    int secondSmallest = Age[0];
    int i;
    for (i = 1; i < n; i++) {
        if (Age[i] < min) {
            secondSmallest = min;
            min = Age[i];
        } else if (Age[i] < secondSmallest && Age[i] != min) {
            secondSmallest = Age[i];
        }
    }
    return secondSmallest;
}

int SecondLargest(int Age[], int n) {
    int max = Age[0];
    int secondLargest = Age[0];
    int i;
    for (i = 1; i < n; i++) {
        if (Age[i] > max) {
            secondLargest = max;
            max = Age[i];
        } else if (Age[i] > secondLargest && Age[i] != max) {
            secondLargest = Age[i];
        }
    }
    return secondLargest;
}

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    if (n <= 0 || n > 125) {
        printf("Invalid: Enter any value between 1 to 125\n");
        return 1; // Exit with an error code
    }

    int age[n];  // Correct the array size
    int ascending = 1;
    int descending = 1;
    int i;

    for (i = 0; i < n; i++) { // Start from 0
        printf("Enter value %d: ", i + 1);
        scanf("%d", &age[i]);
        if (age[i] < 1 || age[i] > 125) {
            printf("Invalid: Age must be between 1 and 125\n");
            return 1;
        }
        if (i > 0) {
            if (age[i] > age[i - 1]) {
                descending = 0;
            } else if (age[i] < age[i - 1]) {
                ascending = 0;
            }
        }
    }

    if (ascending) {
        printf("Invalid: The given values are in ascending order\n");
    } else if (descending) {
        printf("Invalid: The given values are in descending order\n");
    } else {
        // Calculate the statistics
        int minimum = Minimum(age, n);
        int maximum = Maximum(age, n);
        float mean = Mean(age, n);
        float standardDeviation = StandardDeviation(age, n, mean);
        int secondSmallest = SecondSmallest(age, n);
        int secondLargest = SecondLargest(age, n);

        // Display the results
        printf("Minimum: %d\n", minimum);
        printf("Maximum: %d\n", maximum);
        printf("Mean: %.2f\n", mean);
        printf("Standard Deviation: %.2f\n", standardDeviation);
        printf("Second Smallest: %d\n", secondSmallest);
        printf("Second Largest: %d\n", secondLargest);
    }

    return 0;
}

