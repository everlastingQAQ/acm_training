#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    map <int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t] = max(mp[t], mp[t - 1] + 1);
        ans = max(ans, mp[t]);
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