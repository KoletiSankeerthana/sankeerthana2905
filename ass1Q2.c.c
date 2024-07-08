#include <stdio.h>
#include <math.h>
int main()
 
    int set1[4],set2[4],unionset[8],intersectionset[8], differenceset[4];
    int n,p,q=0,r=0,s=0;
    int i,j;
{

    // Input for Set1
    printf("Enter total no.of elements in Set1: ");
    scanf("%d", &n);

    printf("Enter each elements of Set1 (with space): ");
    for (i = 0; i <n; i++)
	 {
        scanf("%d", &set1[i]);
    }

    // Input for Set2
    printf("Enter total no.of elements in Set2: ");
    scanf("%d", &p);

    printf("Enter each element of Set2 (with space): ");
    for ( i = 0; i < p; i++) {
        scanf("%d", &set2[i]);
    }

    // Calculate the union of the sets
    for (i = 0; i <n; i++) 
	{
        unionset[q++] = set1[i];
    }

    for ( i = 0; i <p; i++) {
        int absent = 0;
        for ( j = 0; j <n; j++) {
            if (set2[i] == set1[j]) {
                absent = 1;
                break;
            }
        }
        if (!absent) {
            unionset[q++] = set2[i];
        }
    }

    // Calculate the intersection of the sets
    for (i = 0; i <n; i++) {
        for (j = 0; j <p; j++) {
            if (set1[i] == set2[j]) {
                intersectionset[r++] = set1[i];
                break;
            }
        }
    }

    // Calculate the difference (Set1 - Set2)
    for (i = 0; i < n; i++) {
        int PresentInSet2 = 0;
        for ( j = 0; j <p; j++) {
            if (set1[i] == set2[j]) {
                PresentInSet2 = 1;
                break;
            }
        }
        if (!PresentInSet2) {
            differenceset[s++] = set1[i];
        }
    }

    // show result for union//
    printf("Union of two sets: ");
    for ( i = 0; i <q; i++) {
        printf("%d ", unionset[i]);
    }
    printf ("\n");
    //show result for intersection//
    printf("Intersection of two sets: ");
    for ( i = 0; i <r; i++) {
        printf("%d ", intersectionset[i]);
    }
    printf ("\n");
    //show result for difference//
    printf("Set1 - Set2 (Difference): ");
    for ( i = 0; i <s; i++) {
        printf("%d ", differenceset[i]);
    }
    printf ("\n");

    return 0;
}
}
