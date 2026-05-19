#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    vector <vector <int> > vis(n + 1, vector <int> (n + 1));

    queue <array <int, 3> > q;
    q.push({1, 1, 0});
    vis[1][1] = 1;

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        v[x][y] = z;
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
            if (vis[xx][yy]) continue;
            q.push({xx, yy, z + 1});
            vis[xx][yy] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << v[i][j] << " \n"[j == n];
        }
    }
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