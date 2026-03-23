#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <array <int, 2> > v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    vector <int> dp(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= v[i][0]; j--) {
            dp[j] = max(dp[j], dp[j - v[i][0]] + v[i][0] * v[i][1]);
        }
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