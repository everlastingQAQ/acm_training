#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, -1, 0, 1};

void solve ()
{
    cin >> n;
    vector<vector<ll> > v(n + 2, vector<ll> (n + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        v[i][0] = 0, v[0][i] = 0;
        v[i][n + 1] = 0, v[n + 1][i] = 0;
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            if (v[i][j] == 0) {
                v[i][j] = 2;
            }
        }
    }

    queue<pair<ll, ll> > q;
    q.push({0, 0});

    while (!q.empty()) {
        ll x = q.front().fi, y = q.front().se;
        q.pop();
        v[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] > n + 1 || x + dx[i] < 0) continue;
            if (y + dy[i] > n + 1 || y + dy[i] < 0) continue;
            if (v[x + dx[i]][y + dy[i]] == 2) {
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << v[i][j] << ' ';
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