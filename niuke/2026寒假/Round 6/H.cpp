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

    vector <int> dp(n + 1, 0);
    vector <int> vis(2048 + 1, 0);
    vis[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2048; j++) {
            if (vis[j]) {
                vis[j ^ b[i]] = 1;
                vis[max(j - a[i], 0LL)] = 1;
                dp[i] = max({dp[i], j ^ b[i], j - a[i]});
            }
        }
    }

    cout << dp[n] << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/