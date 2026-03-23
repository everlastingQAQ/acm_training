#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, t;
    cin >> n >> t;
    vector <array <i64, 2> > v(n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
        i64 a, b;
        cin >> a >> b;
        v[i][1] = a - b;
        ans += b;
    }

    vector <i64> dp(n + 1, 0);
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        while (pos + 1 < i && v[i][0] - v[pos + 1][0] >= t) {
            pos++;
        }
        dp[i] = max(dp[i - 1], dp[pos] + v[i][1]);
    }

    cout << ans + dp[n] << '\n';
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