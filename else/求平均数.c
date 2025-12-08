#include <stdio.h>

int main()
{
	printf("This program will help you to calculate the average, please type in the numbers below.\nIf you finish the work, please type in -1 to stop.");
	
    int num = 0;
	int count = 0;
	int sum=0;
	
	scanf("%d", &num);
	
	while (num != -1){
		
		count ++;
		sum += num;
		
		scanf("%d", &num);
		
	} 
	
	double average=1.00*sum/count;
	
	printf("The average is %f", average);
	
	return 0;
}
