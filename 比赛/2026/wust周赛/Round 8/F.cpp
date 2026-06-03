#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> b(n + 1), c(n + 1);
    int mx = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum += c[i];
    }

    vector <int> cost(mx + 1, 1e18);
    cost[1] = cost[0] = 0;
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j >= 1; j--) {
            int cur = i + i / j;
            if (cur > mx) continue;
            cost[cur] = min(cost[cur], cost[i] + 1);
        }
    }
    
    if (k > 20 * n) {
        cout << sum << '\n';
        return;
    }

    vector <int> dp(k + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= cost[b[i]]; j--) {
            dp[j] = max(dp[j], dp[j - cost[b[i]]] + c[i]);
        }
    }

    cout << dp[k] << '\n';
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