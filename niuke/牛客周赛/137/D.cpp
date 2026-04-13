#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
        a[i] = a[i - 1] ^ v[i];
    }

    vector <i64> dp(n + 1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + v[i];
        i64 mn = 1e18;
        for (int j = i - 1; j >= 0; j--) {
            mn = min(mn, dp[j]);
            dp[i] = min(dp[i], mn + (a[i] ^ a[j]));
        }
    }

    cout << dp[n] << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 