#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n, m, k; cin >> n >> m >> k;
    if (((n - 1) / 2) * ((m - 1) / 2) < k) {
        cout << "No" << '\n';
        return;
    }

    vector <vector <ll> > v(n + 1, vector <ll> (m + 1));
    vector <vector <bool> > vis(n + 1, vector <bool> (m + 1, false));

    ll t = n * m;
    if (k != 0) {
        ll cnt = 0;
        bool found = true;
        for (int i = 2; i < n; i += 2) {
            for (int j = 2; j < m; j += 2) {
                cnt++;
                v[i][j] = t--;
                vis[i][j] = true;
                if (cnt == k) {
                    found = false;
                }
                if (!found) break;
            }
            if (!found) break;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) continue;
            v[i][j] = t--;
        }
    }

    cout << "Yes" << '\n';
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
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   