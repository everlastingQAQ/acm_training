#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    ll ans = 0;
    for (int i = 2; i <= n; i += 2) {
        if (v[i - 1] > v[i]) {
            ans += v[i - 1] - v[i];
            v[i - 1] = v[i];
        }
        if (i < n && v[i + 1] > v[i]) {
            ans += v[i + 1] - v[i];
            v[i + 1] = v[i];
        }
        if (i < n && v[i + 1] + v[i - 1] > v[i]) {
            ans += v[i + 1] + v[i - 1] - v[i];
            v[i + 1] -= v[i + 1] + v[i - 1] - v[i];
        }
    }

    cout << ans << '\n';
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