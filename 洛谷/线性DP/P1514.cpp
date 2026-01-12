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
const int N = 50;

ll dp[N][N][N][N];

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <ll> v(n + 1), cnt(5);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= m; i++) {
        ll t; cin >> t;
        cnt[t]++;
    }
    
    dp[0][0][0][0] = v[1];

    for (int i = 0; i <= cnt[1]; i++) {
        for (int j = 0; j <= cnt[2]; j++) {
            for (int k = 0; k <= cnt[3]; k++) {
                for (int l = 0; l <= cnt[4]; l++) {
                    ll pos = 1 + i + j * 2 + k * 3 + l * 4;
                    ll mx = 0;
                    if (i != 0) mx = max(mx, dp[i - 1][j][k][l] + v[pos]);
                    if (j != 0) mx = max(mx, dp[i][j - 1][k][l] + v[pos]);
                    if (k != 0) mx = max(mx, dp[i][j][k - 1][l] + v[pos]);
                    if (l != 0) mx = max(mx, dp[i][j][k][l - 1] + v[pos]);
                    dp[i][j][k][l] = max(dp[i][j][k][l], mx);
                }
            }
        }
    }

    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << '\n';
    
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