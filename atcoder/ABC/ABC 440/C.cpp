#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init()     
{

}

void solve ()
{
    int n, w; cin >> n >> w;
    int m = 2 * w;

    vector <int> v(m, 0);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        v[i % m] += t;
    }

    int cur = 0;
    for (int i = 0; i < w; i++) {
        cur += v[i];
    }

    int ans = cur;

    for (int i = 0; i < m - 1; i++) {
        cur -= v[i % m];
        cur += v[(i + w) % m];
        ans = min(ans, cur);
    }

    cout << ans << '\n';
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}