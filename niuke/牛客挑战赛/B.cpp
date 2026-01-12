#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define fi first
#define se second
#define int long long

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init() 
{

}

void solve ()
{
    int n, m; cin >> n >> m;
    __int128 mm = m;
    __int128 sum = mm * (mm + 1) / 2;
    int ans0 = 0, ans1 = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t & 1 && t - 1 <= sum) {
            ans1++;
        }
        if (!(t & 1) && t - 1 <= sum) {
            ans0++;
        }
    }
    if (m % 4 == 1) {
        cout << ans1 << ' ' << ans0 << '\n';
    }else {
        cout << ans0 << ' ' << ans1 << '\n';
    }
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