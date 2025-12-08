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

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    vector <pi> dp(n + 1, {-1e9 - 10, -1e9 - 10});
    for (ll i = 1; i <= n; i++) {
        dp[i].fi = max({dp[i - 1].se - v[i], dp[i - 1].fi, -v[i]});
        dp[i].se = max({v[i], dp[i - 1].fi + v[i], dp[i - 1].se});
    }

    cout << max(dp[n].fi, dp[n].se) << '\n';

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