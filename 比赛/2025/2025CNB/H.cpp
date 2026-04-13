#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m, q;

void solve ()
{
    cin >> n >> m >> q;
    vector <vector <ll> > v(n + 1, vector <ll> (m + 1, 0));

    while (q--) {
        ll x, y, k, s;
        cin >> x >> y >> k >> s;
        v[x][y] += s;
        for (int i = x - k; i <= x + k; i++) {
            if (i == x) continue;
            ll xx = (i + n - 1) % n + 1;
            v[xx][y] += s;
        }
        for (int i = y - k; i <= y + k; i++) {
            if (i == y) continue;
            ll yy = (i + m - 1) % m + 1;
            v[x][yy] += s;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
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
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}