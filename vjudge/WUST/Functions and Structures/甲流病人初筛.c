#include <stdio.h>

typedef struct Patient
{
	char name[9];
	float tem;
	int is_cough;
}Patient;

int main ()
{
	int n;
	scanf("%d", &n);
	
	Patient patients[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%s %f %d", patients[i].name, &patients[i].tem, &patients[i].is_cough);
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (patients[i].tem >= 37.5 &&patients[i].is_cough == 1) {
			printf("%s\n", patients[i].name);
			cnt++;
		}
	}
	printf("%d", cnt);
	
	return 0;
}
