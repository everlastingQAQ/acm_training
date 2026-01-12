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
    ll n; cin >> n;
    vector <vector <ll> > v(n + 1, vector <ll> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <ll> > dp(n + 5, vector <ll> (n + 5, 0));
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
            mx = max(dp[i][j], mx);
        }
    }

    cout << mx << '\n';
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