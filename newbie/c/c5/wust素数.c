#include <stdio.h>

int main()
{
	int num;
	int i;
	int isprime = 1;
	
	scanf("%d", &num);
	
	if (num == 1) {
		printf("NO");
		goto final;
	}else { 
	
	for (i = 2; i < num; i++){
		if (num % i == 0){
			isprime = 0;
			break;
		}
		
	}
	if (isprime == 1) {
		printf("YES");
	}else {
	    printf("NO"); 
	}
}
final:
	
	return 0;
}
