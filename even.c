#include <stdio.h>
void main()
{
	char ch;
	printf ("\n enter any character");
	scanf ("%c",&ch);
	if (ch>='a'&&ch<='z')
	{
		printf ("\n %c lowercase",ch);
	}
	else if (ch>='A'&&ch<='Z')
	{
		printf ("\n uppercase");
	}
	else 
	{
		printf ("\n not an alphabet");
	}
getch();
}
