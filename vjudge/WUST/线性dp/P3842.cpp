#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    vector <array <int, 2> > dp(n + 1);
    dp[1][0] = v[1][1] - 1 + v[1][1] - v[1][0];
    dp[1][1] = v[1][1] - 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1] + abs(v[i - 1][1] - v[i][1]), dp[i - 1][0] + abs(v[i - 1][0] - v[i][1])) + v[i][1] - v[i][0] + 1;
        dp[i][1] = min(dp[i - 1][0] + abs(v[i - 1][0] - v[i][0]), dp[i - 1][1] + abs(v[i - 1][1] - v[i][0])) + v[i][1] - v[i][0] + 1;
    }

    int ans = min(abs(v[n][0] - n) + dp[n][0], abs(v[n][1] - n) + dp[n][1]);
    cout << ans << '\n';
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