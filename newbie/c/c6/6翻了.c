#include <stdio.h>

void intialize (int n, char temp[n])
{
	for (int i = 0; i < n; i++) {
		temp[i] = '\0';
	}
}

int main ()
{
	char s[1001];
	intialize (1001, s);
	
	int i = 0;
	char c;
	while (i < 1000 && scanf("%c", &c) == 1 && c != '\n') {
		s[i] = c;
		if (s[i] == '6') {
			int count = 1;
			int j = i + 1;
			
			while (j < 1000 && scanf("%c", &c) == 1 && c == '6' && i + count < 1000) {
				count++;
				j++;
			}
			
			if (count > 3 && count <= 9) {
				s[i] = '9';
				i++;
			}else if (count > 9) {
				s[i] = '2';
				s[i + 1] = '7';
				i += 2;
			}else if (count <= 3) {
				for (int k = 0; k < count; k++) {
					s[i + k] = '6';
				}
				i += count;
			}
			
			if (j < 1000 && c != '\n') {
				s[i] = c;
				i++;
			}
			
		}else {
			i++;
		}
	}
	
	s[i] = '\0';
	
	printf("%s", s);
	
	return 0;
	
}
