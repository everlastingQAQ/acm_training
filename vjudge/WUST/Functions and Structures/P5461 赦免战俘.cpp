#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, m;
int a[1100][1100];

void dfs (ll d, ll x, ll y)
{
    if (d == 1 || x < 1 || x > m || y < 1 || y > m) {
        return;
    }

    for (int i = x; i < x + d / 2; i++) {
        for (int j = y; j < y + d / 2; j++) {
            a[i][j] = 0;
        }
    }

    dfs(d / 2, x, y + d / 2);
    dfs(d / 2, x + d / 2, y);
    dfs(d / 2, x + d / 2, y + d / 2);
}

void solve ()
{
    cin >> n;
    m = pow(2, n);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            a[i][j] = 1;
        }
    }
    dfs(m, 1, 1);
    for (int i = 1; i <= m; i++) {
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