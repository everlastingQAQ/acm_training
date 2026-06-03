#include <bits/stdc++.h>
using namespace std;
// #define int long long

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    using arr3 = array <int, 3>;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    vector <arr2> M;
    arr2 st;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') {
                st = {i, j};
            }
            if (v[i][j] == 'M') {
                M.push_back({i, j});
            }
        }
    }

    queue <arr3> q;
    vector <vector <int> > dis(n + 1, vector <int> (m + 1, 1e8));
    for (auto dot : M) {
        q.push({dot[0], dot[1], 0});
        dis[dot[0]][dot[1]] = 0;
    }

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (v[xx][yy] == '#') continue;
            if (dis[xx][yy] <= cnt + 1) continue;
            dis[xx][yy] = cnt + 1;
            q.push({xx, yy, dis[xx][yy]});
        }
    }
 
    vector <vector <int> > a(n + 1, vector <int> (m + 1, -1));
    q.push({st[0], st[1], 0});
    a[st[0]][st[1]] = 1;
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        if (x == 1 || x == n || y == 1 || y == m) {
            cout << "YES\n";
            string s;
            int xx = x, yy = y;
            while (xx != st[0] || yy != st[1]) {
                if (a[xx][yy] == 0) s += 'D', xx--;
                else if (a[xx][yy] == 1) s += 'L', yy++;
                else if (a[xx][yy] == 2) s += 'U', xx++;
                else s += 'R', yy--;
            }
            cout << s.size() << '\n';
            reverse(s.begin(), s.end());
            cout << s;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (v[xx][yy] == '#' || a[xx][yy] != -1) continue;
            if (dis[xx][yy] <= cnt + 1) continue;
            q.push({xx, yy, cnt + 1});
            a[xx][yy] = i;
        }
    }
    cout << "NO\n";
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