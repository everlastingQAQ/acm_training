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

void solve1 ()
{
    ll n, m, t; cin >> n >> m >> t;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    vector a(n + 1, vector<vector<ll> >(m + 1, vector<ll>(t + 1, -1)));

    auto dfs = [&] (ll x, ll y, ll z, auto self) -> ll {
        if (a[x][y][z] != -1) return a[x][y][z];
        if (abs(x - x2) + abs(y - y2) > t - z) return a[x][y][z] = 0;
        if (z == t) {
            if (x == x2 && y == y2) return a[x][y][z] = 1;
            else return a[x][y][z] = 0;
        }

        ll cur = 0;
        for (int i = 0; i < 4; i++) {
            ll xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || v[xx][yy] == '*') continue;
            cur += self(xx, yy, z + 1, self);
        }
        return a[x][y][z] = cur;
    };

    cout << dfs(x1, y1, 0LL, dfs) << '\n';
    return;
}   
 
void solve2 ()
{
    ll n, m, t; cin >> n >> m >> t;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    vector dp(n + 2, vector<vector<ll> >(m + 2, vector<ll>(t + 2, 0)));
    dp[x1][y1][0] = 1;

    for (int k = 1; k <= t; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i][j] == '*') dp[i][j][k] = 0;
                else dp[i][j][k] = dp[i + 1][j][k - 1] + dp[i - 1][j][k - 1] + dp[i][j - 1][k - 1] + dp[i][j + 1][k - 1];
            }
        }
    }

    cout << dp[x2][y2][t] << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve2();
    }
    return 0;
}