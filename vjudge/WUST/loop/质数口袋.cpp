#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
bitset<MAXN + 1> isPrime;
int Prime[10010], cnt = 0;

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
	
	GetPrime(MAXN);
	
	int sum = 0;
	int cnt = 0;
	
	for (int i = 1; i < n; i++) {
		sum += Prime[i];
		if (sum > n) break;
		cnt++;
		cout << Prime[i] << endl;
	}
	cout << cnt << endl;
	return 0;
}
