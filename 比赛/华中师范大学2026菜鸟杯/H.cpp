#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve ()
{
    i64 n, m;
    cin >> n >> m;
    i64 res = m % mod;
    for (int i = m - 1; i >= max(m - 1000, n); i--) {
        res = (res * i) % mod;
    }
    cout << res << '\n';
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