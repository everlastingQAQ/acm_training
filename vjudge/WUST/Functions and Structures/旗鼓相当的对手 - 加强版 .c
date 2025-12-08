#include <stdio.h>
#include <stdlib.h>

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
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(students[i].Chinese - students[j].Chinese) <= 5 && abs(students[i].Math - students[j].Math) <= 5 && abs(students[i].English - students[j].English) <= 5 && abs(sum[i] - sum[j]) <= 10)
			{
				printf("%s %s\n", students[i].name, students[j].name);
			}
		}
	}
	
	return 0;
}
