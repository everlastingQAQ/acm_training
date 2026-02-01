#include <bits/stdc++.h>
using namespace std;
// #define int long long

int dx[3] = {-1, 1, 0};

void solve ()
{
    int n, c; cin >> n >> c;
    vector <vector <char> > v(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (n + 1, 0));
    vector <int> ok(n + 1, 0);
    queue <array<int, 2> > q;

    q.push({c, n});
    vis[n][c] = true;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int xx = x + dx[i], yy = y - 1;
            if (xx > n || xx < 1 || yy > n || yy < 1) continue;
            if (vis[yy][xx]) continue;
            if (!ok[xx]) {
                ok[xx] = true;
                bool found = false;
                for (int j = yy + 1; j <= n; j++) {
                    if (v[j][xx] == '#') {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    for (int j = yy; j >= 1; j--) {
                        v[j][xx] = '.';
                    }
                }
            }
            if (v[yy][xx] == '.') {
                vis[yy][xx] = true;
                q.push({xx, yy});
            }
        }   
    }

    for (int i = 1; i <= n; i++) {
        cout << vis[1][i];
    }
    cout << '\n';
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