#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <vector <ll> > v(n + 1, vector <ll> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vector <vector <ll> > a(n + 1, vector <ll> (m + 1, 0));
            auto dfs = [&] (ll x, ll y, auto self) -> ll {
                if (a[x][y]) return a[x][y];
                a[x][y] = 1;
                for (int i = 0; i < 4; i++) {
                    ll xx = x + dx[i], yy = y + dy[i];
                    if (xx > n || xx < 1 || yy > m || yy < 1 || v[xx][yy] >= v[x][y]) continue;
                    self(xx, yy, self);
                    a[x][y] = max(a[x][y], a[xx][yy] + 1);
                }
                return a[x][y];
            };
            ll t = dfs(i, j, dfs);
            ans = max(ans, t);
        }
    }

    cout << ans << '\n';
}   
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}