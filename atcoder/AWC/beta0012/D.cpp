#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > a(n + 1, vector <int> (m + 1, -1));
    queue <array <int, 2> > q;
    q.push({1, 1});
    a[1][1] = 0;

    int cnt = 0;
    while (1) {
        queue <array <int, 2> > qq;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n && y == m) {
                cout << a[x][y] << '\n';
                return;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (a[xx][yy] != -1) continue;
                if (v[xx][yy] == '#') {
                    a[xx][yy] = a[x][y] + 1;
                    qq.push({xx, yy});
                }else {
                    a[xx][yy] = a[x][y];
                    q.push({xx, yy});
                }
            }
        }
        cnt++;
        q = qq;
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