#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    vector <ll> a(mx + 1, 0);
    for (int i = 0; i < n; i++) {
        a[v[i]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= mx; i++) {
        if (a[i] >= 2) {
            ll t = a[i] * (a[i] - 1) / 2;
            ans += (n - a[i]) * t;
        }
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