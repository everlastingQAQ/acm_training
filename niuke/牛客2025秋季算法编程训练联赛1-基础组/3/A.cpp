#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
ll n, m;

void solve ()
{
    cin >> n >> m;
    char v[51][51];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    ll a[51][51];
    a[0][0] = 1;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                if (v[i][j - 1] == 'D') {
                    a[i][j] = 0;
                }else {
                    a[i][j] = a[i][j - 1];
                }
            }

            if (j == 0) {
                if (v[i - 1][j] == 'R') {
                    a[i][j] = 0;
                }else {
                    a[i][j] = a[i - 1][j];
                }
            }

            if (i != 0 && j != 0) {
                if (v[i - 1][j] != 'R' && v[i][j - 1] != 'D') {
                    a[i][j] = (a[i - 1][j] + a[i][j - 1]) % mod;
                }else if (v[i - 1][j] == 'R' && v[i][j - 1] != 'D') {
                    a[i][j] = a[i][j - 1] % mod;
                }else if (v[i - 1][j] != 'R' && v[i][j - 1] == 'D') {
                    a[i][j] = a[i - 1][j] % mod;
                }
            }
        }
    }

    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = a[n - 1][m - 1] % mod;

    cout << ans << endl;
    
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