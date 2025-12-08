#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

ll n, m, h;

void solve ()
{
    cin >> n >> m >> h;
    vector <vector <ll> > d(n + 3, vector <ll> (m + 3, 0));

    auto add = [&] (ll x1, ll y1, ll x2, ll y2, ll t) {
        d[x1][y1] += t;
        d[x1][y2 + 1] -= t;
        d[x2 + 1][y1] -= t;
        d[x2 + 1][y2 + 1] += t;
    };

    ll a, b, c;
    for (int i = 0; i < h; i++) {
        cin >> a >> b >> c;
        add(a, 1, a, m, c);
        add(1, b, n, b, c);
        add(a, b, a, b, -c);
    }

    vector <vector <ll> > ans(n + 2, vector <ll> (m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = d[i][j] + ans[i][j - 1] + ans[i - 1][j] - ans[i - 1][j - 1];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << ans[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll t = ((i + j) * ans[i][j]) % mod;
            sum += t;
            sum %= mod;
        }
    }

    cout << sum << '\n';
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