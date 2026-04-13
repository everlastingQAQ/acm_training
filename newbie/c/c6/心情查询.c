#include <stdio.h>

void Traverse1 (int n, int s[n])
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
}

void initialize_Traverse2 (int n, int s[n])
{
	for (int i = 0; i < n; i++) {
		s[i] = -1;
	}
	
	int i = 0;
	int j;
	
	while (i < n - 1 && scanf("%d", &j) == 1) {
		if (j < 0 || j > 23) {
			break;
		}else {
			s[i++] = j;
		}
	}
}

int main ()
{
	const int n = 24;
	
	int s[n];
	Traverse1(n, s);

	int hour[n + 1];
	initialize_Traverse2(n + 1, hour);

	int i = 0;
	
	while (i < n + 1 && hour[i] != -1) {
		
		if (s[hour[i]] > 50) {
			printf("%d Yes", s[hour[i]]);
		}else if (s[hour[i]] <= 50) {
			printf("%d No", s[hour[i]]);
		}
		
		if (s[hour[i + 1]] != -1) {
			printf("\n");
		}else {
			break;
		}
		i++;
	}
	
	return 0;
	
}
