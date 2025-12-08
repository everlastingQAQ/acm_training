#include <stdio.h>

int main ()
{
	int s[17];
	int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	
	int i = 0;
	int sum = 0;
	
	while (i < 17 && scanf("%1d", &s[i]) == 1) {
		sum += s[i] *a[i];
		i++;
	}
	
	char b;
	scanf("%c", &b);
	
	sum %= 11;
	
	int z[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	
	char mask = '0';
	
	for (int i = 0; i < 11; i++) {
		if (sum == z[i]) {
			mask = m[i];
		}
	}
	
	if (mask == b) {
		printf("No problem");
	}else {
		printf("Incorrect");
	}
	
	return 0;		
}
