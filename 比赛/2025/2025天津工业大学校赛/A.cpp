#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, x;
    cin >> n >> x;
    vector <int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    vector <int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= v[i]; j--) {
            dp[j] |= dp[j - v[i]];
        }
    }

    int ans = 1e15;
    for (int i = 0; i <= sum; i++) {
        if (dp[i]) {
            ans = min(ans, abs(x + 2 * i - sum));
        }
    }
    
    cout << ans << '\n';
}   
    
int main ()
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
