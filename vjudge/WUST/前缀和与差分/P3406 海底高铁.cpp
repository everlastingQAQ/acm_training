#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <ll> v(m + 1);
    vector <ll> d(n + 2, 0);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }

    for (int i = 2; i <= m; i++) {
        ll mx = max(v[i], v[i - 1]);
        ll mn = min(v[i], v[i - 1]);
        d[mn]++;
        d[mx]--;
    }

    vector <ll> a(n + 1, 0);
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + d[i];
    }

    // for (int i = 1; i < n; i++) {
    //     cout << a[i] << '\n';
    // }

    ll j, k, l;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> j >> k >> l;
        ans += min(j * a[i], k * a[i] + l);
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