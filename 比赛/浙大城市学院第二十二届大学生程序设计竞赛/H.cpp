#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, -1, 0, 1};

void solve ()
{
    ll n, m; cin >> n >> m;
    ll sx, sy;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    vector <vector <bool> > vis(n + 1, vector <bool> (m + 1, false));
    vector <array<ll, 2> > a;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == '#') vis[i][j] = true;
            if (v[i][j] == 'S') sx = i, sy = j;
            if (v[i][j] == '*') a.push_back({i, j});
        }
    }

    ll ans = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        queue <array<ll, 3> > q;
        q.push({sx, sy, 0});

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            if (x != sx && y != sy && v[x][y] == '*') {
                ans += d;
                sx = x, sy = y;
                cnt++;
                break;
            }
            
            for (int i = 0; i < 4; i++) {
                ll xx = x + dx[i], yy = y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) continue; 
                vis[xx][yy] = true;
                q.push({xx, yy, d + 1});
            }
        }
        // cout << cnt << ' ' << ans << '\n';
        // cout << sx << ' ' << sy << '\n';
    }

    if (cnt == a.size()) {
        cout << ans * 2 << '\n';
    }else {
        cout << -1 << '\n';
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