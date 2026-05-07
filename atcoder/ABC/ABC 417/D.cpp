#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    vector <vector <array<int, 2> > > g(26);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] >= 'a' && v[i][j] <= 'z') {
                g[v[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    vector <vector <bool> > vis(n + 1, vector <bool> (m + 1, false));
    vector <bool> vs(26);

    queue<array<ll, 3> > q;   
    vis[1][1] = true;
    q.push({1, 1, 0});

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        if (x == n && y == m) {
            cout << d << '\n';
            return;
        }
        for (int i = 0; i < 4; i++) {
            ll xx = x + dx[i], yy = y + dy[i];
            if (xx > n || xx < 1 || yy > m || yy < 1 || v[xx][yy] == '#' || vis[xx][yy]) continue;
            q.push({xx, yy, d + 1});
            vis[xx][yy] = true; 
        }
        if (v[x][y] >= 'a' && v[x][y] <= 'z' && !vs[v[x][y] - 'a']) {
            vs[v[x][y] - 'a'] = true;
            for (auto [xx, yy] : g[v[x][y] - 'a']) {
                if (!vis[xx][yy]) {
                    vis[xx][yy] = true;
                    q.push({xx, yy, d + 1});
                }
            }
        }
    }
    cout << -1 << '\n';
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