#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> d(n + 10), dd(n + 10);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        dd[i] = dd[i - 1] + d[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dd[i] & 1) ans++;
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