#include <stdio.h>

int main ()
{
	char str[81] = {'\0'};
	gets(str);
	
	int cnt = 0;
	int mask_English = 0;
	int mask_number = 0;
	int mask = 1;
	
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			mask_number = 1;
			cnt++;
			continue;
		}
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			mask_English = 1;
			cnt++;
			continue;
		}
		if (str[i] == '.') {
			cnt++;
			continue;
		}
		mask = 0;
	}
	
	if (cnt < 6) {
		printf("Your password is tai duan le.");
		return 0;
	}
	if (mask == 0) {
		printf("Your password is tai luan le.");
		return 0;
	}
	
	if (mask_number == 1 && mask_English == 0) {
		printf("Your password needs zi mu.");
	}
	if (mask_number == 0 && mask_English == 0) {
		printf("Your password zhi you dian.");
	}
	if (mask_number == 0 && mask_English == 1) {
		printf("Your password needs shu zi.");
	}
	
	if (mask_number == 1 && mask_English == 1) {
		printf("Your password is wan mei.");
	}
	
	return 0;
}
