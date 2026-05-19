#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> dp(n + 1);
    dp[1] = 1;
    i64 pre = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (pre + 1) % mod;
        pre = (pre + dp[i]) % mod;
    }
    cout << dp[n] << '\n';
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