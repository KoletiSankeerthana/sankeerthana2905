 #include <stdio.h>
int main() {
    int n;
    int digits[8];
    int length,i;
    
    // Input
    printf("Enter a number:");
    scanf("%d", &n);
    
    // Check if the input number is within the specified range
    if (n<10000 || n>99999999 )
	{
        printf("\n Invalid: Enter a number with minimum 5 digits and maximum 8 digits");
    }
   else if (n<0)
	{
	printf("\n Invalid: Enter positive number");
		}    
    
    // Extract digits from the number and store them in an array
    
    while (n> 0) 
	{
	    length=1;
        digits[length] = n% 10;
        n/= 10;
        length++;
    
    }
    
    // Loop through the digits to find three consecutive 3's
    for (i = 1; i < length - 2; i++)
	 {
        if (digits[i] == 3 && digits[i + 1] == 3 && digits[i + 2] == 3) 
		{
            
			printf("\n Three consecutive 3's starting from right to left at position %d",i);
            return 0;
        }
    
    }
    // If no three consecutive 3's were found
        
	printf("\n No three consecutive 3's ");
          

    return 0;
}

