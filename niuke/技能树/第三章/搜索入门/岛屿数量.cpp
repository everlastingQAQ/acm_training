#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
    int ans = 0;

    auto dfs = [&] (int x, int y, auto self) -> void {
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx > n || xx < 1 || yy > m || yy < 1) continue;
            if (vis[xx][yy] || v[xx][yy] == '.') continue;
            vis[xx][yy] = 1;
            self(xx, yy, self);
        }
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && v[i][j] == 'W') {
                ans++;
                vis[i][j] = 1;
                dfs(i, j, dfs);
            }
        }
    }

    cout << ans << '\n';
}   
    
signed main ()
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