#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n, m; cin >> n >> m; 
    map <pi, bool> mp;

    ll ans = 0;
    while (m--) {
        ll x, y; cin >> x >> y;
        if (mp.count({x, y}) == 0 &&
            mp.count({x + 1, y}) == 0 &&
            mp.count({x, y + 1}) == 0 &&
            mp.count({x + 1, y + 1}) == 0) {
            
            ans++;
            mp[{x, y}] = true;
            mp[{x + 1, y}] = true;
            mp[{x, y + 1}] = true;
            mp[{x + 1, y + 1}] = true;
        }
    }
    cout << ans << '\n';
}

int main ()
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