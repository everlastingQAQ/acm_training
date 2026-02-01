#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void solve ()
{
    int n, m; cin >> n >> m;
    vector <int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector <array<int, 2>> e;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e.push_back({u , v});
    }

    sort(e.begin(), e.end(), [&] (const auto a, const auto b) {
        return w[a[1]] < w[b[1]];
    });

    int ans = 0;
    map <int, int> dp[n + 1];
    for (auto [u, v] : e) {
        ans = (ans + dp[u][w[v] - w[u]] + 1) % mod;
        dp[v][w[u]] = (dp[v][w[u]] + dp[u][w[v] - w[u]] + 1) % mod;
    }

    cout << ans << '\n';

}   
    
int32_t main ()
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