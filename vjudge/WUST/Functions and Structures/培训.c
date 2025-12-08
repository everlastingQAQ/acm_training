#include <stdio.h>

typedef struct information 
{
	char name[100];
	int age;
	int grade;
	
}information;

void increase_print (int len, information *p)
{
	for (int i = 0; i < len; i++) {
		information *q = p + i;
		if (q->grade / 5 + q->grade <= 600) {
			q->grade = q->grade / 5 + q->grade;
		}else {
			q->grade = 600;
		} 
		q->age++;
		printf("%s %d %d", q->name, q->age, q->grade);
		if (i < len - 1) {
			printf("\n");
		}
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	information infor[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", infor[i].name, &infor[i].age, &infor[i].grade);
	}
	
	increase_print(n, infor);
	
	return 0;
	
}
