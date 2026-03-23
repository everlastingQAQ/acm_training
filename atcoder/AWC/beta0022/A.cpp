#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, d, k;
    cin >> n >> d >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t - d * k > 0) {
            ans++;
        }
    }
    cout << ans << '\n';
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