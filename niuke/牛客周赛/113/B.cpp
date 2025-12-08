#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main ()
{
    int n;
    cin >> n;
    
    long long x, y;
    cin >> x >> y;
    long long a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        long long ans1 = ((a * x - b * y) % mod + mod) % mod;
        long long ans2 = ((a * y + x * b) % mod + mod) % mod;
        x = ans1;
        y = ans2;
    }

    cout << x << ' ' << y;

    return 0;
}