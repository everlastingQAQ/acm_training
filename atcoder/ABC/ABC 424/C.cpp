#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n;

void solve ()
{
    cin >> n;
    vector <vector <ll> > e(n + 1);
    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        e[a].push_back(i);
        e[b].push_back(i);
    }

    vector <bool> vis(n + 1, false);
    vis[0] = true;

    auto dfs = [&] (ll x, auto &&self) -> void {
        vis[x] = true;
        for (auto t : e[x]) {
            if (!vis[t]) {
                self(t, self);
            }
        }
    };  

    dfs(0, dfs);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            ans++;
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