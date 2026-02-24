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

    vector <int> dp(n + 2, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[v[i]] = max(dp[v[i] - 1], dp[v[i] + 1]) + 1;
        ans = max(dp[v[i]], ans);
    }
    
    cout << ans << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/