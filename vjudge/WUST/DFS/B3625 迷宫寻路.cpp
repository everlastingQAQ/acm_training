#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;
char ch[110][110];
bool vis[110][110];

int mox[4] = {1, 0, -1, 0};
int moy[4] = {0, -1, 0, 1};

void dfs (ll x, ll y)
{
    if (x == n && y == m) {
        cout << "Yes" << '\n';
        exit(0);
    }

    for (int i = 0; i < 4; i++) {
        int xx = x + mox[i];
        int yy = y + moy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m || ch[xx][yy] == '#' || vis[xx][yy]) {
            continue;
        }
        vis[xx][yy] = true;
        dfs(xx, yy);
    }
}

void solve ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch[i][j];
        }
    }

    dfs(1, 1);

    cout << "No" << '\n';
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