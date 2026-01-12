#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int x, y, n; cin >> x >> y >> n;
    map <int, int> mp;
    vector <int> v(x), a(y);
    for (int i = 0; i < x; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < y; i++) {
        cin >> a[i];
    }

    if (v[x - 1] != a[y - 1] || x + y - 1 > n) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < x; i++) {
        cout << v[i] << ' ';
    }
    for (int i = 0; i <= n - x - y; i++) {
        cout << v[x - 1] << ' ';
    }
    for (int i = y - 2; i >= 0; i--) {
        cout << a[i] << ' ';
    }
    
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}