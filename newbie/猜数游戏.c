#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("Number Guessing Game\nThe number is between 0 and 100.");
	
	srand(time(0));
	int num = rand()%100;
	
	int a = 0;
	int count = 0;
	
	do{
		printf("\nPlease input a num:");
		
		scanf("%d", &a);
		
		count++;
		
		if (a > num) 
		   printf("     Your num is too large.");
		else if (a < num)
		   printf("     Your num is too small.");   
	} while (a != num);
	
	printf("Lucky you!\nYou have gussed %d times", count);
	
	return 0;
}
