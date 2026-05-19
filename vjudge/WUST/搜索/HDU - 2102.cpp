#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m, t;
    cin >> n >> m >> t;
    int enz, enx, eny;
    vector <vector <vector <char> > > v(2, vector <vector <char> >(n + 1, vector <char> (m + 1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[0][i][j];
            if (v[0][i][j] == 'P') {
                enz = 0;
                enx = i;
                eny = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[1][i][j];
            if (v[1][i][j] == 'P') {
                enz = 1;
                enx = i;
                eny = j;
            }
        }
    }

    vector <vector <vector <int> > > vis(2, vector <vector <int> >(n + 1, vector <int> (m + 1)));
    priority_queue <array <int, 4>, vector <array <int, 4> >, greater<array <int, 4> > > pq;
    pq.push({0, 1, 1, 0});
    vis[0][1][1] = true;
    // cout << enz << " " << enx << ' ' << eny << '\n';

    while (!pq.empty()) {
        auto [cnt, x, y, z] = pq.top();
        pq.pop();
        // cout << z << ' ' << x << ' ' << y << ' ' << cnt << '\n';
        if (z == enz && x == enx && y == eny) {
            // cout << z << ' ' << x << ' ' << y << ' ' << cnt << '\n';
            cout << (cnt <= t ? "YES\n" : "NO\n");
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            // cout << xx << ' ' << yy << '\n';
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (vis[z][xx][yy]) continue;
            vis[z][xx][yy] = true;
            if (v[z][xx][yy] == '#') {
                if (z == 0) {
                    if (!vis[z + 1][xx][yy]) {
                        vis[z + 1][xx][yy] = true;
                        if (v[z + 1][xx][yy] == '.' || v[z + 1][xx][yy] == 'P') {
                            pq.push({cnt + 1, xx, yy, z + 1});
                        }else if (v[z + 1][xx][yy] == '#') {
                            vis[z + 1][xx][yy] = true;
                        }
                    }
                }else if (z == 1) {
                    if (!vis[z - 1][xx][yy]) {
                        vis[z - 1][xx][yy] = true;
                        if (v[z - 1][xx][yy] == '.' || v[z - 1][xx][yy] == 'P') {
                            pq.push({cnt + 1, xx, yy, z - 1});
                        }else if (v[z - 1][xx][yy] == '#') {
                            vis[z - 1][xx][yy] = true;
                        }
                    }
                }
            }else if (v[z][xx][yy] == '.') {
                pq.push({cnt + 1, xx, yy, z});
            }else if (v[z][xx][yy] == 'P') {
                pq.push({cnt + 1, xx, yy, z});
            }
        }
    }
    cout << "NO\n";
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