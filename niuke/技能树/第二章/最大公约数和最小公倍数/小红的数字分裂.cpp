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
    int n; cin >> n;
    vector <int> v(n + 1);
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i == 1) t = v[i];
        else t = gcd(t, v[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += v[i] / t - 1;
    }

    cout << ans << '\n';
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}