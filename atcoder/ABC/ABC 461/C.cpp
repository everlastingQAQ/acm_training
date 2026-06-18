#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k, m;
    cin >> n >> k >> m;
    using arr2 = array <int, 2>;
    vector <arr2> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1] >> v[i][0];
    }

    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        return a[0] > b[0];
    });

    map <int, int> mp1, mp;
    int cnt = 0;
    int ans = 0; 

    for (int i = 1; i <= n; i++) {
        if (!mp1[v[i][1]]) {
            mp1[v[i][1]] = true;
            mp[i] = true;
            ans += v[i][0];
            if (++cnt >= m) break;
        }
    }

    if (cnt < k) {
        for (int i = 1; i <= n; i++) {
            if (mp[i]) continue;
            ans += v[i][0];
            if (++cnt >= k) break;
        }
    }
    
    cout << ans << '\n';
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