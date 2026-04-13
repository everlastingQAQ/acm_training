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
    vector <i64> dp(n + 1);
    dp[1] = 0;

    i64 t1 = 1e18, t2 = 1e18;
    if (v[1] & 1) {
        t1 = 1;
    }else {
        t2 = 1;
    }

    i64 ans = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] & 1 && t1 != 1e18) {
            
        }
    }

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