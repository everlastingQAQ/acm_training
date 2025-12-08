#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000000;
bitset<MAXN + 1> isPrime;
int Prime[7000010], cnt = 0;

void GetPrime(int n)
{
	isPrime.set();
	isPrime[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			Prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * Prime[j] <= n; j++) {
			isPrime[i * Prime[j]] = 0;
			if (i % Prime[j] == 0) {
				break;
			}
		}
	}
}

bool isPalindrome(int x) {
	if (x < 10) return true;
	int ori = x;
	int rs = 0;
	while (x > 0) {
		rs = rs * 10 + x % 10;
		x /= 10;
	}
	return ori == rs;
}

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	GetPrime(m);
	
	for (int i = 1; i <= cnt; i++) {
		int p = Prime[i];
		if (p < n) continue;
		if (p > m) break;
		if (isPalindrome(p)) {
			printf("%d\n", p);
		}
	}
	
	return 0;
	
}
