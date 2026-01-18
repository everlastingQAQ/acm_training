#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (mp[v[i]] == 0) {
            m++;
        }
        mp[v[i]]++;
    }

    ranges::sort(v | views::drop(1));
    ranges::unique(v | views::drop(1));

    int l = 1, r = 2;
    int ans = 1;
    while (r <= m) {
        while (r <= m && v[r] == v[r - 1] + 1) {
            r++;
        }
        ans = max(ans, r - l);
        l = r;
        r++;
    }

    cout << ans << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}