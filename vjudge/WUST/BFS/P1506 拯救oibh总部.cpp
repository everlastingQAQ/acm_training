#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll x, y;
char c[510][510];
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, -1, 0, 1};
queue<pair<ll, ll> > q;

void bfs (ll xx, ll yy)
{
    while (!q.empty()) {
        auto [xx, yy] = q.front();
        q.pop();
        c[xx][yy] = '*';
        for (int i = 0; i < 4; i++) {
            if (xx + dx[i] < 1 || xx + dx[i] > x) continue;
            if (yy + dy[i] < 1 || yy + dy[i] > y) continue;
            if (c[xx + dx[i]][yy + dy[i]] == '0') {
                q.push({xx + dx[i], yy + dy[i]});
            }
        }
    }
}

void solve ()
{
    cin >> x >> y;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= x; i++) {
        if (c[i][1] == '0') {
            q.push({i, 1});
            c[i][1] = '*';
            bfs(i, 1);
        }
    }

    for (int i = 1; i <= x; i++) {
        if (c[i][y] == '0') {
            q.push({i, y});
            c[i][y] = '*';
            bfs(i, y);
        }
    }

    for (int i = 1; i <= y; i++) {
        if (c[1][i] == '0') {
            q.push({1, i});
            c[1][i] = '*';
            bfs(1, i);
        }
    }

    for (int i = 1; i <= y; i++) {
        if (c[x][i] == '0') {
            q.push({x, i});
            c[x][i] = '*';
            bfs(x, i);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (c[i][j] == '0') {
                ans++;
            }
        }  
    }

    cout << ans;
}    

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _; 
    while (_--) {
        solve();
    }
    return 0;
}