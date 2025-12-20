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
    vector <ll> v(n);
    for (ll &x : v) cin >> x;

    vector <ll> dp(n);
    dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    }   

    cout << *max_element(dp.begin(), dp.end()) << '\n';
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