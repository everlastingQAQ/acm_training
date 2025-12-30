#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    vector <array<ll, 3> > dp(n + 1, {(ll)-1e16, (ll)-1e16, (ll)-1e16});
    dp[1][0] = a[1];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
    }

    cout << dp[n][2] << '\n';
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