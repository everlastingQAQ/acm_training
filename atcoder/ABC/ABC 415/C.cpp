#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector <int> dp((1 << n) + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') continue;
        for (int j = n; j >= i; j--) {
            if (s[j - i] == '1') continue;
            dp[j - i] = 1;
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