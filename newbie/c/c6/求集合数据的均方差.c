#include <stdio.h>
#include <math.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n];
	double sum = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		sum += s[i];
	}
	
	double average = sum / n;
	
	double a;
	
	for (int i = 0; i < n; i++) {
		a += (s[i] - average) * (s[i] - average);
	}
	
	a /= n;
	
	double result = sqrt(a);
	
	printf("%.5f", result);
	
	return 0;
}
