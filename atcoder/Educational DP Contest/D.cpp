#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, w; cin >> n >> w;
    vector <array<int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1] >> v[i][0];
    }

    vector <int> dp(1e5 + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= v[i][1]; j--) {
            dp[j] = max(dp[j], dp[j - v[i][1]] + v[i][0]);
        }
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