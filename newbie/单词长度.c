#include <stdio.h>

int main ()
{
	char ch;
	
	int cnt = 0;
	
	while(scanf("%c", &ch) != EOF && ch != '\n') {
		if (ch == ' ') {
			if (cnt != 0) {
				printf("%d ", cnt);
				cnt = 0;
			}
			
		}else {
			cnt++;
		}
	}
	
	if (cnt != 0) {
		printf("%d", cnt);
	}else {
		printf("0");
	}
	
	return 0;
}
