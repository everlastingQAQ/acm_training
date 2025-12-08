#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
bitset<MAXN + 1> isPrime;
int Prime[1000010], cnt = 0;

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

int main ()
{
	int n;
	cin >> n;
	GetPrime(1000000);
	cout << Prime[n] << endl;
	return 0;
}
