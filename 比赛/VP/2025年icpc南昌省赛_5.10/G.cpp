#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    vector <vector <int> > dp(n + 2, vector <int> (40, 1));
    for (int i = 1; i <= 32; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j][i] > 1e9) continue;
            for (auto [v, w] : e[j]) {
                dp[j][i] = max(dp[j][i], dp[v][i - 1] * w);
                if (dp[j][i] > 1e9) break;
            }
        }
    }
    
    while (Q--) {
        int st, val;
        cin >> st >> val;
        for (int i = 1; i <= 33; i++) {
            if (dp[st][i] > val) {
                cout << i << '\n';
                break;
            }
        }
    }
}   

int32_t main ()
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