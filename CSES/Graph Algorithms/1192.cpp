#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (m + 1));
    int ans = 0;
    using arr2 = array <int, 2>;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == '#') continue;
            if (vis[i][j]) continue;
            queue <arr2> q;
            q.push({i, j});
            vis[i][j] = true;
            ans++;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    if (vis[xx][yy] || v[xx][yy] == '#') continue;
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
        }
    }

    cout << ans << '\n';
}   
    
int32_t main ()
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