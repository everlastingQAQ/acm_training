#include <stdio.h>

int main()
{
	printf("Type in a number and check if it's a prime:");
	
	int num;
	int i;
	int isprime = 1;
	
	scanf("%d", &num);
	
	for (i = 2; i < num; i++){
		if (num % i == 0){
			isprime = 0;
			break;
		}
		
	}
	if (isprime == 1){
		printf("The number is a prime.");
	}else{printf("The number is Not a prime."); 
	}
	
	return 0;
}
