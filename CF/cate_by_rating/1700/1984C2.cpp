#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <array <int, 2> > dp(n + 1), cnt(n + 1);
    dp[1][0] = abs(v[1]);
    dp[1][1] = v[1];
    if (v[1] >= 0) {
        cnt[1][0] = cnt[1][1] = 2;
    } else {
        cnt[1][0] = cnt[1][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(abs(dp[i - 1][0] + v[i]), abs(dp[i - 1][1] + v[i]));
        dp[i][1] = dp[i - 1][1] + v[i];
        if (dp[i][0] == dp[i - 1][0] + v[i]) {
            cnt[i][0] = (cnt[i][0] + cnt[i - 1][0]) % mod;
        }

        if (dp[i][0] == abs(dp[i - 1][0] + v[i]) && dp[i - 1][0] != dp[i - 1][1]) {
            cnt[i][0] = (cnt[i][0] + cnt[i - 1][0]) % mod;
        }

        if (dp[i][0] == abs(dp[i - 1][1] + v[i])) {
            cnt[i][0] = (cnt[i][0] + cnt[i - 1][1]) % mod;
        }

        cnt[i][1] = cnt[i - 1][1];
        if (dp[i][1] == abs(dp[i - 1][1] + v[i])) {
            cnt[i][1] = (cnt[i][1] + cnt[i - 1][1]) % mod;
        }
    }

    cout << cnt[n][0] << '\n';
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