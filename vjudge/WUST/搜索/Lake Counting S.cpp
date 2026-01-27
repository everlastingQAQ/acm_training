#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;
ll ans = 0;
char c[101][101];
bool vis[101][101];
ll dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
ll dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs (ll x, ll y)
{
    for (int i = 0; i < 8; i++) {
        ll xx = x + dx[i];
        ll yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (c[xx][yy] == 'W' && !vis[xx][yy]) {
            vis[xx][yy] = true;
            dfs(xx, yy);
        }
    }
}

void solve ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'W' && !vis[i][j]) {
                ans++;
                vis[i][j] = true;
                dfs(i, j);
            }
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