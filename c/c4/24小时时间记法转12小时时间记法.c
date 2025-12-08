#include <stdio.h>

int main()
{
	int hor, min, sec;
	scanf("%d %d %d", &hor, &min, &sec);
	
	if (hor >= 12) {
		printf("%d %d %d PM", hor-12, min, sec);
	}else {
		printf("%d %d %d AM", hor, min, sec);
	}
	
	return 0;
	
}
