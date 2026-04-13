#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > v(n + 5, vector <int> (m + 5, 0));
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
    }

    int ans = k;
    auto dfs = [&] (auto self, int cnt) -> void {
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    int xxx = i + 2 * dx[k];
                    int yyy = j + 2 * dy[k];
                    if (xxx < 1 || xxx > n || yyy < 1 || yyy > m) continue;
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    if (v[xx][yy] == 0 || v[xxx][yyy] == 1) continue;
                    v[i][j] = 0;
                    v[xx][yy] = 0;
                    v[xxx][yyy] = 1;
                    ok = true;
                    self(self, cnt - 1);
                    v[i][j] = 1;
                    v[xx][yy] = 1;
                    v[xxx][yyy] = 0;
                }
            }
        }
        if (!ok) ans = min(ans, cnt);
        else ans = min(ans, cnt - 1);
    };
    dfs(dfs, k);

    cout << ans << '\n';
} 

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 