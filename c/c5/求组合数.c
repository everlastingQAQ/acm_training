#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	double N = 1;
	
	for (int numN = 1; numN <= n; numN++) {
		N *= numN;
	}
	
	double M = 1;
	
	for (int numM = 1; numM <= m; numM++) {
		M *= numM;
	}
	
	double C = 1;
	
	for (int numC = 1; numC <= m - n; numC++) {
		C *= numC;
	}
	
	double res = M / N / C;
	
	printf("%.0f", res);
	
	return 0;
}
