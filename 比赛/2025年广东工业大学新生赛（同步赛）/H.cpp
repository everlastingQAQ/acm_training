#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    vector <pi> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ll ans = 0;
    dp[0].fi = 0, dp[0].se = 0;
    dp[1].fi = v[1], dp[1].se = 0;
    for (int i = 2; i <= n; i++) {
        dp[i].fi = dp[i - 1].se + v[i];
        dp[i].se = max(dp[i - 2].fi, dp[i - 2].se) + v[i];
    }

    cout << max(dp[n].fi, dp[n].se) << '\n';
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