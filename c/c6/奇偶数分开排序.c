#include <stdio.h>

void sorting (int num[], int n) 
{
	for (int i = n - 1; i > 0; i--) {
		int tag = i;
		for (int j = i - 1; j >= 0; j--) {
			if (num[tag] < num[j]) {
				tag = j;
			}
		}
		int t = num[i];
		num[i] = num[tag];
		num[tag] = t;
	}
}

void print (int num[], int n) 
{
	int mask = 1;
	
	for (int i = 0; i < n; i++) {
		if (mask == 1) {
			printf("%d", num[i]);
			mask = 0;
		}else {
			printf(" %d", num[i]);
		}
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	int odd[n];
	int even[n];
	
	int cnt1 = 0;
	int cnt2 = 0;
	
	for (int i = 0; i < n; i++) {
		if (num[i] % 2 == 1) {
			odd[cnt1] = num[i];
			cnt1++;
		}else {
			even[cnt2] = num[i];
			cnt2++;
		}
	}
	
	sorting(odd, cnt1);
	sorting(even, cnt2);
	
	print(odd, cnt1);
	printf(" ");
	print(even, cnt2);
	
	return 0;
	
}
