#include <stdio.h>

int main ()
{
	char s[10000];
	scanf("%[^\n]", s);
	
	int cnt[26] = {0};
	
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cnt[s[i] - 'A']++;
		}
	}
	
	for (int i = 0; i < 26; i++) {
		printf("%c(%d)", 'A' + i, cnt[i]);
		if ((i + 1) % 5 == 0) {
			printf("\n");
		}
	}
	
	return 0;
	
}
