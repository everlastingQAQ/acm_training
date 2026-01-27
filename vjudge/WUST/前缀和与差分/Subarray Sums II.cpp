#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x; cin >> n >> x;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    map <int, int> mp;
    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += v[i];
        if (cur == x) ans++;
        ans += mp[cur - x];
        mp[cur]++;
    }
    cout << ans << '\n';
}   
    
signed main ()
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