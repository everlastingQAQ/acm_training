#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector <array <int, 2> > dp(n + 1);
    dp[1][0] = 0;
    dp[1][1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + abs(a[i] - a[i - 1]), dp[i - 1][1] + abs(a[i] - b[i - 1]));
        dp[i][1] = min(dp[i - 1][0] + abs(b[i] - a[i - 1]), dp[i - 1][1] + abs(b[i] - b[i - 1]));
    }

    cout << min(dp[n][0], dp[n][1]) << '\n';
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