#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <ll> ans(n + 1);
    vector <ll> vis(n + 1, false);

    ll t = 0;
    for (int i = 1; i <= n; i++) {
        ll count = 0;
        auto dfs = [&] (ll x, ll cnt, auto self) -> void {
            if (vis[x]) {
                count = cnt;
                return;
            }
            vis[x] = true;
            self(v[x], cnt + 1, self);
        };
        dfs(v[a[i]], 0LL, dfs);
        ans[i] = ans[i - 1] + count;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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