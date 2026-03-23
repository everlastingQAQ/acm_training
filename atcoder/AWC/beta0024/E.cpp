#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, w;
    cin >> n >> w;
    vector <int> l(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> c[i];
    }

    vector <int> dp(w + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector <int> ndp = dp;
        for (int j = 0; j <= w; j++) {
            if (dp[j] == 1e9) continue;
            for (int k = 1; k <= c[i]; k++) {
                if (j + k * l[i] > w) break;
                ndp[j + k * l[i]] = min(ndp[j + k * l[i]], dp[j] + k);
            }
        }
        dp = ndp;
    }

    cout << (dp[w] == 1e9 ? -1 : dp[w]) << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 