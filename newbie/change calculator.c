#include <stdio.h>

int main()
{
	int price, bill;
	
	printf("Please input the price and the bill:");
	
	scanf("%d %d", &price, &bill);
	
	int change=bill-price;
	
	if(change<0){
		
		printf("The bill is insufficient");
		
		return 0;
	}
	
		printf("change=%d", change);
		
		return 0;
	
}
