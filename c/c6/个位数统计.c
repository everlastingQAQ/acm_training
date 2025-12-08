#include <stdio.h>

int main ()
{
	char s[1001];
	gets(s);
	
	int cnt[10] = {0};
	
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[s[i] - '0']++;//！！！
		}
	}
	
	for (int i = 0; i < 10; i++) {
		if (cnt[i] != 0) {
			printf("%d:%d\n", i, cnt[i]);
		}
	}
	return 0;
}
