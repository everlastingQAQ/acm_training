#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main ()
{
    int n;
    cin >> n;

    long long s1 = 0;
    long long s2 = 1;
    for (int i = 1; i <= n; i++) {
        s1 += i % 5;
        if (i != n) {
            s2 *= i;
            s2 %= mod;
        }
    }

    long long ans = ((s1 % mod) * (s2 % mod)) % mod;

    cout << ans;

    return 0;
}