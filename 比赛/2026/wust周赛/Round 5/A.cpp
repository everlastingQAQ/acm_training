#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int h, w;
    cin >> h >> w;
    vector <vector <char> > v(h + 1, vector <char> (w + 1));
    array <int, 2> st, en;
    int count = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'o') {
                if (count == 0) {
                    st[0] = i;
                    st[1] = j;
                    count++;
                }else {
                    en[0] = i;
                    en[1] = j;
                }
            }

        }
    }

    queue <array <int, 3> > q;
    q.push({st[0], st[1], 0});
    vector <vector <int> > vis(h + 1, vector <int> (w + 1, 0));
    vis[st[0]][st[1]] = true;
        
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        if (x == en[0] && y == en[1]) {
            cout << cnt << '\n';
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > h || yy < 1 || yy > w) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = true;
            q.push({xx, yy, cnt + 1});
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