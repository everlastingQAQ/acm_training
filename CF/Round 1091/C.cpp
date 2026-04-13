#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && gcd(n, m) <= 2) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 