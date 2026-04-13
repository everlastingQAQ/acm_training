#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
}point;

const int N = 1e6 + 5;
Point a[N];

void solve ()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector <vector <int> > v(n + 2, vector <int> (m + 2));
    bool ok = false;
    if (n == 1 || m == 1) ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (!ok) {
                a[v[i][j]].x = i;
                a[v[i][j]].y = j;
            }
        }
    }

    int vis[n + 1][m + 1] = {};
    for (int i = 0; i <= n * m - 1; i++) {
        int x = a[i].x;
        int y = a[i].y;
        if (vis[x][y]) {
            printf("%d\n", i);
            for (int p = 0; p <= n * m - 1; p++) {
                a[p].x = 0;
                a[p].y = 0;
            }
            return;
        }
        
        if (y != m || x != 1) {
            for (int j = x - 1; j >= 1; j--) {
                if (vis[j][y + 1]) break;
                for (int k = y + 1; k <= m; k++) {
                    if (vis[j][k]) {
                        break;
                    }
                    vis[j][k] = true;
                }
            }
        }
        
        if (y != 1 || x != n) {
            for (int j = x + 1; j <= n; j++) {
                if (vis[j][y - 1]) break;
                for (int k = y - 1; k >= 1; k--) {
                    if (vis[j][k]) {
                        break;
                    }
                    vis[j][k] = true;
                }
            }
        }
    }
    printf("%d\n", n * m);

    for (int i = 0; i <= n * m - 1; i++) {
        a[i].x = 0;
        a[i].y = 0;
    }
} 

int main ()
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