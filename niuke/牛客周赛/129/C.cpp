#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k; cin >> n >> m >> k;
    set <int> v;
    map <int, int> mp;
    int cnt = 0;
    for (int i = 1; i <= n * m; i++) {
        int t; cin >> t; 
        if (t == 0) cnt++;
        else v.insert(t), mp[t]++;
    }

    int mx = ranges::max(v);
    int p = v.size();

    int ans1 = 0, ans2 = 0;
    bool ok = false;
    for (auto x : v) {
        if (x >= k - 1) ok = true;
        // cout << x << ' ' << mp[x] << '\n';
        ans1 += mp[x] / 2;
        mp[x + 1] += mp[x] / 2;
        if (ok) ans2 += mp[x] / 2;
        if (v.count(x + 1) == 0 && mp[x + 1] > 1) v.insert(x + 1); 
    }

    cout << ans1 << ' ' << ans2 << '\n';
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