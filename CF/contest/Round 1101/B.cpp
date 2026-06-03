#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> dp(n + 1);
    int lft = 0;
    int sum = 0;
    dp[1] = v[1];
    sum = v[1];
    for (int i = 2; i <= n; i++) {
        sum += v[i];
        if (v[i] > dp[i - 1]) {
            dp[i] = dp[i - 1];
            lft += v[i] - dp[i - 1];
        }else {
            int cur = lft + v[i];
            if (cur < dp[i - 1]) {
                dp[i] = sum / i;
                lft = sum % i;
            }else {
                dp[i] = dp[i - 1];
                lft -= dp[i - 1] - v[i];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
    }
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