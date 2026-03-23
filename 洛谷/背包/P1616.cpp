#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 t, m;
    cin >> t >> m;
    vector <i64> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
     
    vector <i64> dp(t + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = a[i]; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }

    cout << dp[t] << '\n';
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