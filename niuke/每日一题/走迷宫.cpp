#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
    queue <array <int, 3> > q;
    q.push({sx, sy, 0});
    vis[sx][sy] = 1;

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        if (x == tx && y == ty) {
            cout << z << '\n';
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (vis[xx][yy] || v[xx][yy] == '*') continue;
            q.push({xx, yy, z + 1});
            vis[xx][yy] = 1;
        }
    }

    cout << -1 << '\n';

} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 