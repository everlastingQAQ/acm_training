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
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) continue;
            vis[i][j] = true;
            queue <array <int, 2> > q;
            q.push({i, j});
            int xl, xr, yl, yr;
            xl = xr = i;
            yl = yr = j;
            int cnt = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                cnt++;
                xl = min(x, xl);
                xr = max(x, xr);
                yl = min(y, yl);
                yr = max(y, yr);
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    if (vis[xx][yy]) continue;
                    if (v[xx][yy] != v[i][j]) continue;
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
            if ((xr - xl + 1) * (yr - yl + 1) != cnt) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}   

int32_t main ()
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