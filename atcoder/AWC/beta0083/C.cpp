#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    int l = 1, r = 1;
    int cur = 0;
    int ans = 0;
    while (r <= n) {
        cur += v[r][1];
        while (l < r && cur > m) {
            cur -= v[l][1];
            l++;
        }
        if (cur <= m) ans = max(ans, v[r][0] - v[l][0]);
        r++;
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