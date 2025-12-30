#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        ll a, b; cin >> a >> b;
        map <ll, ll> mp;
        for (int i = -1; i <= 1; i++) {
            mp[a + i] = 1;
            mp[b + i] = 1;
        }
        for (auto [x, y] : mp) {
            v[x]++;
        }
    }
    while (m--) {
        ll t; cin >> t;
        cout << n - v[t] << " \n"[m == 0];
    }
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