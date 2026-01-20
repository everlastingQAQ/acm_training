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
    int n; cin >> n;
    vector <vector <char> > v(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (n + 1, 0));

    vector <array<int, 4> > rec;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == '1' && !vis[i][j]) {
                int lx = i, ly = j, rx = i, ry = j;
                auto dfs = [&] (int x, int y, auto self) -> void {
                    lx = min(lx, x), ly = min(ly, y);
                    rx = max(rx, x), ry = max(ry, y);
                    for (int i = 0; i < 8; i++) {
                        int xx = x + dx[i], yy = y + dy[i];
                        if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
                        if (vis[xx][yy] || v[xx][yy] == '0') continue;
                        vis[xx][yy] = true;
                        self(xx, yy, self);
                    }
                };
                dfs(i, j, dfs);
                rec.push_back({lx, ly, rx, ry});
            }
        }
    }

    vector <vector <int> > ans(n + 1, vector <int> (n + 1, 0));

    for (auto [lx, ly, rx, ry] : rec) {
        for (int i = lx; i <= rx; i++) {
            for (int j = ly; j <= ry; j++) {
                ans[i][j] = 1;
            }
        }
    }
    vector <array<int, 4> > rec1;
    rec1 = rec;
   
    do {
        rec1 = rec;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                vis[i][j] = 0;
            }
        }   
        rec.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ans[i][j] == 1 && !vis[i][j]) {
                    int lx = i, ly = j, rx = i, ry = j;
                    auto dfs1 = [&] (int x, int y, auto self) -> void {
                        lx = min(lx, x), ly = min(ly, y);
                        rx = max(rx, x), ry = max(ry, y);
                        for (int i = 0; i < 8; i++) {
                            int xx = x + dx[i], yy = y + dy[i];
                            if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
                            if (vis[xx][yy] || ans[xx][yy] == 0) continue;
                            vis[xx][yy] = true;
                            self(xx, yy, self);
                        }
                    };
                    dfs1(i, j, dfs1);
                    rec.push_back({lx, ly, rx, ry});
                }
            }
        }

        for (auto [lx, ly, rx, ry] : rec) {
            for (int i = lx; i <= rx; i++) {
                for (int j = ly; j <= ry; j++) {
                    ans[i][j] = 1;
                }
            }
        }
    }while (rec != rec1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}   
    
signed main ()
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