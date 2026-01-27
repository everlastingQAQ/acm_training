#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m, t;
ll sx, sy, fx, fy;
ll ans = 0;
bool vis[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs (ll x, ll y)
{
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] > n || x + dx[i] < 1) continue;
        if (y + dy[i] > m || y + dy[i] < 1) continue;
        if (vis[x + dx[i]][y + dy[i]]) continue;
        vis[x + dx[i]][y + dy[i]] = true;
        dfs(x + dx[i], y + dy[i]);
        vis[x + dx[i]][y + dy[i]] = false;
    }
}

void solve ()
{  
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        vis[a][b] = true;
    }
    vis[sx][sy] = true;
    dfs(sx, sy);
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