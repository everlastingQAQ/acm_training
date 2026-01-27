#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;
};

int n, m, t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    point s, d;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'S') s.x = i, s.y = j;
            if (v[i][j] == 'D') d.x = i, d.y = j;
        }
    } 

    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));

    bool found = false;
    auto dfs = [&] (int x, int y, int T, auto self) -> void {
        if (found) return;
        if (T > t) return;
        
        if (x == d.x && y == d.y) {
            if (T == t) {
                cout << "YES" << '\n';
                found = true;
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (vis[xx][yy] || v[xx][yy] == 'X') continue;

            int dist = abs(xx - d.x) + abs(yy - d.y);
            if (dist > t - T - 1) continue;
            if ((dist ^ (t - T - 1)) & 1) continue;

            vis[xx][yy] = true;

            self(xx, yy, T + 1, self);
            vis[xx][yy] = false;
            if (found) return;
        }
    };

    vis[s.x][s.y] = true;
    dfs(s.x, s.y, 0, dfs);

    if (!found) {
        cout << "NO" << '\n';
    }
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    while (cin >> n >> m >> t) {
        if (n == 0 && m == 0 && t == 0) break;
        solve();
    } 
    return 0;
} 