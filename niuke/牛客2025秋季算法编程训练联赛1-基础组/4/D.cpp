#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n);
    for (ll &x : v) cin >> x;
    map <ll, ll> mp;
    ll t = 0, ans = 0;
    mp[0] = 1;

    for (int i = 0; i < n; i++) {
        t ^= v[i];
        ans += mp[t];
        mp[t]++;
    }

    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}