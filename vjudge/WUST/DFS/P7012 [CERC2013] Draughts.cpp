#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

char c[11][11];
ll mox[4] = {1, 1, -1, -1};
ll moy[4] = {1, -1, 1, -1};
ll ans = 0;

void dfs(ll x, ll y, ll cnt)
{
    if (c[x + 1][y - 1] != 'B' && c[x + 1][y + 1] != 'B' && c[x - 1][y + 1] != 'B' && c[x - 1][y - 1] != 'B') {
        ans = max(ans, cnt);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (x + 2 * mox[i] > 10 || x + 2 * mox[i] < 1 || y + 2 * moy[i] > 10 || y + 2 * moy[i] < 1) {
            continue;
        }
        if (c[x + mox[i]][y + moy[i]] == 'B' && c[x + 2 * mox[i]][y + 2 * moy[i]] == '#') {
            c[x][y] = '#';
            c[x + 2 * mox[i]][y + 2 * moy[i]] = 'W';
            c[x + mox[i]][y + moy[i]] = '#';
            dfs(x + 2 * mox[i], y + 2 * moy[i], cnt + 1);
            c[x][y] = 'W';
            c[x + 2 * mox[i]][y + 2 * moy[i]] = '#';
            c[x + mox[i]][y + moy[i]] = 'B';
        }
    } 

    ans = max(ans, cnt);
}

void solve ()
{
    ans = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (c[i][j] == 'W') {
                dfs(i, j, 0);
            }
        }
    }

    cout << ans << '\n';
}

int main ()
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