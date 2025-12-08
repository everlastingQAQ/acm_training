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
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector <pi> dp(n + 1);
    dp[1].fi = max(-a[1], b[1]);
    dp[1].se = min(-a[1], b[1]);
    for (int i = 2; i <= n; i++) {
        dp[i].fi = max(dp[i - 1].fi - a[i], b[i] - dp[i - 1].se);
        dp[i].se = min(dp[i - 1].se - a[i], b[i] - dp[i - 1].fi);
    }
    cout << dp[n].fi << '\n';
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