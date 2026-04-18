#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int b, n, m, k;
    cin >> b >> n >> m >> k;
    vector <vector <array <int, 2> > > dis(n + 1, vector <array <int, 2> > (n + 1, {(int)1e8, -1}));
    for (int i = 1; i <= n; i++) {
        dis[i][i][0] = 0;
        dis[i][i][1] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        dis[u][v][0] = min(dis[u][v][0], a);
        dis[u][v][1] = max(dis[u][v][1], b);
        dis[v][u][0] = min(dis[v][u][0], a);
        dis[v][u][1] = max(dis[v][u][1], b);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j][0] > dis[i][k][0] + dis[k][j][0]) {
                    dis[i][j][0] = dis[i][k][0] + dis[k][j][0];
                    dis[i][j][1] = dis[i][k][1] + dis[k][j][1];
                }
                if (dis[i][j][0] == dis[i][k][0] + dis[k][j][0]) {
                    if (dis[i][j][1] < dis[i][k][1] + dis[k][j][1]) {
                        dis[i][j][1] = dis[i][k][1] + dis[k][j][1];
                    }
                }
            }
        }
    }

    while (k--) {
        int x;
        cin >> x;
        int mx = -1;
        bool ok = false;
        vector <int> a1, a2;
        a1.reserve(n);
        a2.reserve(n);
        for (int i = 1; i <= n; i++) {
            if (i == x) continue;
            if (dis[x][i][0] <= b) {
                ok = true;
                a1.push_back(i);
                mx = max(mx, dis[x][i][1]);
            }
        }
        if (!ok) {
            cout << "T_T\n";
            continue;
        }
        for (auto y : a1) {
            if (dis[x][y][1] == mx) a2.push_back(y);
            cout << y << " \n"[y == a1.back()];
        }
        for (auto y : a2) {
            cout << y << " \n"[y == a2.back()];
        }
    }

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