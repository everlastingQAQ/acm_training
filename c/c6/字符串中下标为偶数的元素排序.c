#include <stdio.h>

void sorting (char num[], int n) 
{
	for (int i = n - 1; i > 0; i--) {
		int tag = i;
		for (int j = i - 1; j >= 0; j--) {
			if (num[tag] < num[j]) {
				tag = j;
			}
		}
		char t = num[i];
		num[i] = num[tag];
		num[tag] = t;
	}
}

int main ()
{
	char str[1001];
	gets(str);
	
	char s[1001];
	
	int j = 0;
	
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (i % 2 == 0) {
			s[j++] = str[i];
		}
	}
	
	sorting(s, j);
	
	j = 0;
	
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (i % 2 == 0) {
			str[i] = s[j++];
		}
	}
	
	printf("%s", str);
	
	return 0;
	
}
