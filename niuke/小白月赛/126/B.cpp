#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    map <ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        mp[t] = true;
    }

    ll mx = 0;
    ll cnt = 0;

    for (int i = 1; i <= 16; i++) {
        if (!mp[(i + n - 1) % 8 + 1]) cnt++;
        else cnt = 0;
        mx = max(mx, cnt);
    }

    cout << 7 - mx << '\n';
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}