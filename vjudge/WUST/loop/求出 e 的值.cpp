#include <bits/stdc++.h>
using namespace std;

long long factorial (int n)
{
	long long res = 1;
	while (n > 0) {
		res *= n;
		n--;
	}
	return res;
}


int main ()
{
	int n;
	cin >> n;
	
	long double e = 1;
	for (int i = 1; i <= n; i++) {
		e += 1.0 / factorial(i);
	}
	
	printf("%.10Lf", e);
	
	return 0;
}
