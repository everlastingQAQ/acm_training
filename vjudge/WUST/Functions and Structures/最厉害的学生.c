#include <stdio.h>

typedef struct student
{
	char name[9];
	int Chinese;
	int Math;
	int English;
	
}student;

int main ()
{
	int n;
	scanf("%d", &n);
	
	struct student students[n];
	
	int sum[n];
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", students[i].name, &students[i].Chinese, &students[i].Math, &students[i].English);
		sum[i] = students[i].Chinese + students[i].Math + students[i].English;
	}
	
	int max_i = 0;
	int max = sum[0];
	for (int i = 1; i < n; i++) {
		if (sum[i] > max) {
			max_i = i;
			max = sum[i];
		}
	}
	
	printf("%s %d %d %d", students[max_i].name, students[max_i].Chinese, students[max_i].Math, students[max_i].English);
	
	return 0;
}
