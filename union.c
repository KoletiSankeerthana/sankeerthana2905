#include <stdio.h>

int main() {
    int set1[10], set2[10];
    int size1, size2;
    int i;
    // Input for Set1
    printf("Enter the number of elements in Set1: ");
    scanf("%d", &size1);
    printf("Enter the elements of Set1: ");
    for ( i = 0; i < size1; i++) 
	{
        scanf("%d", &set1[i]);
    }

    // Input for Set2
    printf("Enter the number of elements in Set2: ");
    scanf("%d", &size2);

    printf("Enter the elements of Set2: ");
    for ( i = 0; i < size2; i++)
	 {
        scanf("%d", &set2[i]);
    }

    // Union of the sets
    int unionSet[20];
    int sizeUnion = size1;
    int i,j;
    for ( i = 0; i < size2; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionSet[sizeUnion] = set2[i];
            sizeUnion++;
        }
    }

    // Intersection of the sets
    printf("Intersection of the two sets: ");
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                printf("%d ", set1[i]);
                break;
            }
        }
    }
    printf("\n");

    // Set1 - Set2 (Difference)
    printf("Set1 - Set2 (Difference): ");
    for (int i = 0; i < size1; i++) {
        int isPresentInSet2 = 0;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                isPresentInSet2 = 1;
                break;
            }
        }
        if (!isPresentInSet2) {
            printf("%d ", set1[i]);
        }
    }
    printf("\n");

    // Display the union
    printf("Union of the two sets: ");
    for ( i = 0; i < size1; i++) {
        printf("%d ", set1[i]);
    }
    for ( i = 0; i < sizeUnion; i++) {
        printf("%d ", unionSet[i]);
    }
    printf("\n");

    return 0;
}

