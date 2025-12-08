#include <stdio.h>

typedef struct information
{
	int id;
	int grade;
	int result;
	
}information;

int main ()
{
	int n;
	scanf("%d", &n);
	
	struct information informations[n];
	int final[n];
	int is_good[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &informations[i].id, &informations[i].grade, &informations[i].result);
		final[i] = informations[i].grade * 7 +informations[i].result * 3;
		if (final[i] >= 800 && informations[i].grade + informations[i].result > 140) {
			is_good[i] = 1;
		}else{
			is_good[i] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (is_good[i]) {
			printf("Excellent\n");
		}else {
			printf("Not excellent\n");
		}
	}
	
	return 0;
}
