#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int num, t; cin >> num >> t;
        int temp;
        while (cin >> temp) {
            if (temp == 0) break;
            dp[num] = max(dp[num], dp[temp]);
        }
        dp[num] += t;
    }
    cout << ranges::max(dp | views::drop(1)) << '\n';
}   
    
signed main ()
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