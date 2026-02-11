#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    point a[2]; 
    point b[2];
    int cnta = 0, cntb = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == '1') {
                a[cnta].x = i;
                a[cnta].y = j;
                cnta++;
            }
            if (v[i][j] == '2') {
                b[cntb].x = i;
                b[cntb].y = j;
                cntb++;
            }
        }
    }

    auto cal = [&] (const point a[2], const point b[2]) -> bool {
        vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
        queue <array<int, 2> > q;
        q.push({a[0].x, a[0].y});
        vis[a[0].x][a[0].y] = true;

        vector <vector <point> > pre(n + 1, vector <point> (m + 1, {-1, -1}));

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == a[1].x && y == a[1].y) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (vis[xx][yy]) continue;
                if (!(xx == a[1].x && yy == a[1].y) && v[xx][yy] != '0') {
                    continue;
                }
                pre[xx][yy] = {x, y};
                vis[xx][yy] = true;
                q.push({xx, yy});
            }
        }

        if (!vis[a[1].x][a[1].y]) return false;
        vis.assign(n + 1, vector <int> (m + 1, 0));
        
        point cur = a[1];
        while (!(cur.x == -1 && cur.y == -1)) {
            vis[cur.x][cur.y] = 1;
            if (cur.x == a[0].x && cur.y == a[0].y) break;
            cur = pre[cur.x][cur.y];
        }

        while (q.size()) {
            q.pop();
        }
        
        q.push({b[0].x, b[0].y});
        vis[b[0].x][b[0].y] = true;

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == b[1].x && y == b[1].y) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (vis[xx][yy]) continue;
                if (!(xx == b[1].x && yy == b[1].y) && v[xx][yy] != '0') {
                    continue;
                }
                vis[xx][yy] = true;
                q.push({xx, yy});
            }
        }

        return vis[b[1].x][b[1].y];
    };

    cout << (cal(a, b) || cal(b, a) ? "YES" : "NO") << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/