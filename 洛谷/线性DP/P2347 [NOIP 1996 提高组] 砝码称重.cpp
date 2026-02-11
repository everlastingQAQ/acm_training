#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    vector <int> a = {0, 1, 2, 3, 5, 10, 20};
    vector <int> v(7);
    for (int i = 1; i <= 6; i++) {
        cin >> v[i];
    }
    int ans = 0;
    vector <int> dp(10050);
    dp[0] = 1;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= v[i]; j++) {
            for (int k = 1000; k >= 0; k--) {
                if (dp[k]) dp[k + a[i]] = 1;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (dp[i]) ans++;
    }

    cout << "Total=" << ans << '\n';
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