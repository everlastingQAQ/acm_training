#include <stdio.h>

int main () 
{
	
	int n;
	scanf("%d", &n);
	
	int grade[n];
	double aver = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &grade[i]);
		aver += grade[i];
	}
	
	aver /= n;
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		if (grade[i] > aver) {
			cnt++;
		}
	}
	
	int min = grade[0];
	
	for (int i = 1; i < n; i++) {
		if (grade[i] < min) {
			min = grade[i];
		}
	}
	
	int max = grade[0];
	
	for (int i = 1; i < n; i++) {
		if (grade[i] > max) {
			max = grade[i];
		}
	}
	
	printf("%d %d %d", max, min, cnt);
	
	return 0;
}
