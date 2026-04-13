#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int t, n;
    cin >> t >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]] = 1;
    }

    int x;
    cin >> x;
    int ans = 0;
    for (int i = t; i <= x; i++) {
        if (mp[i]) continue;
        ans++;
    }
    cout << ans << '\n';
} 

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 