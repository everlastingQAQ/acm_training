#include <bits/stdc++.h>
using namespace std;
// #define int long long

struct point {
    int x, y;
};

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

char p[4] = {'D', 'L', 'R', 'U'};

void solve ()
{   
    int n, m, k; cin >> n >> m >> k;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    point s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'X') s.x = i, s.y = j;
        }
    }

    if (k & 1) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    vector <vector <int> > dist(n + 1, vector <int> (m + 1, 1e11));
    vector <vector <int> > vis(n + 1, vector <int> (m + 1));

    queue <point> q;
    q.push({s.x, s.y});
    dist[s.x][s.y] = 0;

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || v[xx][yy] == '*' || vis[xx][yy]) continue;
            dist[xx][yy] = min(dist[xx][yy], dist[x][y] + 1);
            q.push({xx, yy});
        }
    }

    string ans;

    auto dfs = [&] (int x, int y, int sum, auto self) -> void {
        if (sum == k && x == s.x && y == s.y) {
            cout << ans << '\n';
            exit(0);
        }
        if (sum >= k || dist[x][y] > k - sum) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || v[xx][yy] == '*') continue;
            ans.push_back(p[i]);
            self(xx, yy, sum + 1, self);
            ans.pop_back();
        }
    };

    dfs(s.x, s.y, 0, dfs);

    cout << "IMPOSSIBLE" << '\n';

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