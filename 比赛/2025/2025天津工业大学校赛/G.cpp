#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector <double> dp(n + 1);
    dp[1] = 1;
    k = min(k, 50);
    for (int i = 1; i <= k; i++) {
        vector <double> ndp(n + 1);
        for (int j = 1; j <= n; j++) {
            ndp[j] = dp[j] / (n - j + 1);
            if (j > 1) ndp[j] += ndp[j - 1];
        }
        dp = ndp;
    } 
    
    while (q--) {
        int x;
        cin >> x;
        cout << fixed << setprecision(10);
        cout << dp[x] << '\n';
    }
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