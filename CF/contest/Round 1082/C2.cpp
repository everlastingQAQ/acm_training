#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <array <i64, 2> > stk;
    vector <i64> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        while (stk.size() && v[i] != stk.back()[0] + 1) {
            stk.pop_back();
        }
        if (stk.empty()) {
            dp[i] = dp[i - 1] + i;
        }else {
            dp[i] = dp[i - 1] + i - stk.back()[1];
        }
        stk.push_back({v[i], i});
    }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
    }

    cout << ans << '\n';
}   
    
int main ()
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