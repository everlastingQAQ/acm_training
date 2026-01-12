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
    int x, y; cin >> x >> y;
    int ans = 0;
    while ((x & y) != x) {
        ans++;
        x >>= 1;
    }
    cout << ans + (x != y) << '\n';
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