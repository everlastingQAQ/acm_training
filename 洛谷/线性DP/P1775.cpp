#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <i64> v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }

    vector <vector <i64> > dp(n + 1, vector <i64> (n + 1, 1e11));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            int l = j, r = j + i - 1;
            i64 val = pre[r] - pre[l - 1];
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + val);
            }
        }
    }

    cout << dp[1][n] << '\n';
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
