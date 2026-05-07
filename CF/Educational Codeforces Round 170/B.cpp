#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n;
    cin >> n;
	vector <array <i64, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1];
    }
    
    for (int i = 1; i <= n; i++) {
        if (v[i][1] == 0 || v[i][0] == v[i][1]) {
            cout << 1 << '\n';
            continue;
        }
        i64 ans = qpow(2, v[i][1]);
        cout << ans << '\n';
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}