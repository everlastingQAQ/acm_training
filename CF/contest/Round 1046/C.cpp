#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    vector <vector <ll> > p(n + 1);
    vector <ll> cnt(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        p[v[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cnt[v[i]]++;
        if (cnt[v[i]] >= v[i]) {
            dp[i] = v[i] + dp[p[v[i]][cnt[v[i]] - v[i]] - 1];
        }
        dp[i] = max(dp[i - 1], dp[i]);
        cout << dp[i] << ' ';
    }

    cout << dp[n] << '\n';
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