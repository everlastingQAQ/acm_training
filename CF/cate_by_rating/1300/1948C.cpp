#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <char> > s(n + 1, vector <char> (2));
    for (int i = 0; i < n; i++) {
        cin >> s[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i][1];
    }
    bool ok = false;
    vector <vector <int> > vis(n + 1, vector <int> (2, 0));
    auto dfs = [&] (auto self, int x, int y) -> void {
        if (x >= n) return;
        if (x == n + 1 && y == 1) {
            ok = true;
            return;
        }
        // cout << x << ' ' << y << '\n';
        if (y == 0) {
            if (x == n - 1) {
                ok = true;
                return;
            }
            if (s[x + 1][y] == '>') {
                if (!vis[x + 2][y]) {
                    vis[x + 2][y] = true;
                    self(self, x + 2, y);
                    if (ok) return;
                }
            }
            if (s[x][y + 1] == '>') {
                if (!vis[x + 1][y + 1]) {
                    vis[x + 1][y + 1] = true;
                    self(self, x + 1, y + 1);
                    if (ok) return;
                }
            }else {
                if (x < 1) return;
                if (!vis[x - 1][y + 1]) {
                    vis[x - 1][y + 1] = true;
                    self(self, x - 1, y + 1);
                    if (ok) return;
                }
            }
        }else {
            if (x == n - 1 || x == n - 2) {
                ok = true;
                return;
            }
            if (s[x + 1][y] == '>') {
                if (!vis[x + 2][y]) {
                    vis[x + 2][y] = true;
                    self(self, x + 2, y);
                    if (ok) return;
                }
            }
            if (s[x][y - 1] == '>') {
                if (!vis[x + 1][y - 1]) {
                    vis[x + 1][y - 1] = true;
                    self(self, x + 1, y - 1);
                    if (ok) return;
                }
            }else {
                if (x < 1) return;
                if (!vis[x - 1][y - 1]) {
                    vis[x - 1][y - 1] = true;
                    self(self, x - 1, y - 1);
                    if (ok) return;
                }
            }
            if (ok) return;
        }
    };
    vis[0][0] = true;
    dfs(dfs, 0, 0);
    cout << (ok ? "YES\n" : "NO\n");
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