#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m, k;

void solve ()
{
    cin >> n >> m >> k;
    vector <pi> v(k);
    vector <vector <ll> > vis(n + 1, vector <ll> (m + 1));
    for (int i = 0; i < k; i++) {
        cin >> v[i].fi >> v[i].se;
        vis[v[i].fi][v[i].se] = true;
    }

    ll mx = 0;
    ll ansx = 1, ansy = 1;

    auto check = [&] (ll x, ll y) {
        ll mnn = 201;
        for (auto [xx, yy] : v) {
            mnn = min(mnn, abs(xx - x) + abs(yy - y));
        }
        if (mnn > mx) {
            ansx = x;
            ansy = y;
            mx = mnn;
        }
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) continue;
            check(i, j);
        }
    }

    cout << mx << '\n';
    cout << ansx << ' ' << ansy << '\n';
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