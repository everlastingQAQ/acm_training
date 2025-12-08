#include <stdio.h>

int main ()
{
	int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int b[4][4];
	int h, l;
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			scanf("%d", &b[i][j]);
			if (b[i][j] == 0) {
				h = i;
				l = j;
			}
			for (int k = 0; k < 9; k++) {
				if (b[i][j] == a[k]) {
					a[k] = -1;
					break;
				}
			}
		}
	}
	
	for (int k = 0; k < 9; k++) {
		if (a[k] != -1) {
			b[h][l] = a[k];
			break;
		}
	}
	
	int c[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	
	int d;
	scanf("%d", &d);

	for (int i = 0; i < 3; i++) {
		int q = 0;
		int w = 1;
		printf("%d\n", b[c[i][q]][c[i][w]]);
	}
	
	int sum = 0;
	
	if (d >= 1 && d <= 3) {
		for (int i = 1; i < 4; i++) {
			sum += b[d][i];
		}
	}
	
	if (d >= 4 && d <= 6) {
		for (int i = 1; i < 4; i++) {
			sum += b[i][d - 3];
		}
	}
	
	if (d == 7) {
		for (int i = 1; i < 4; i++) {
			sum += b[i][i];
		}
	}
	
	if (d == 8) {
		for (int i = 1; i < 4; i++) {
			sum += b[i][4 - i];
		}
	}
	
	int price;
	
	if (sum == 6) price = 10000;
	if (sum == 7) price = 36;
	if (sum == 8) price = 720;
	if (sum == 9) price = 360;
	if (sum == 10) price = 80;
	if (sum == 11) price = 252;
	if (sum == 12) price = 108;
	if (sum == 13) price = 72;
	if (sum == 14) price = 54;
	if (sum == 15) price = 180;
	if (sum == 16) price = 72;
	if (sum == 17) price = 180;
	if (sum == 18) price = 119;
	if (sum == 19) price = 36;
	if (sum == 20) price = 306;
	if (sum == 21) price = 1080;
	if (sum == 22) price = 144;
	if (sum == 23) price = 1800;
	if (sum == 24) price = 3600;
	
	printf("%d", price);
	
	return 0;
}
