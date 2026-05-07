#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> dp(n + 1);
    ll ans = n;
    for (int i = 1; i <= n; i++) {
        if (dp[i - 1] < i && i != 1) {
            ans = dp[i - 1];
            break;
        }
        dp[i] = max(dp[i - 1], i + v[i] - 1);
    }

    cout << ans << '\n';
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