#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m, x, y;
int a[401][401];
bool vis[401][401];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void solve ()
{
    cin >> n >> m >> x >> y;
    memset(a, -1, sizeof(a));

    queue<pair<ll, ll> > q;
    q.push({x, y});
    a[x][y] = 0;

    while (!q.empty()) {
        auto [xx, yy] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            ll xn = xx + dx[i], yn = yy + dy[i];
            if (xn < 1 || xn > n) continue;
            if (yn < 1 || yn > m) continue;
            if (a[xn][yn] == -1) {
                a[xn][yn] = a[xx][yy] + 1;
                q.push({xn, yn});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

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