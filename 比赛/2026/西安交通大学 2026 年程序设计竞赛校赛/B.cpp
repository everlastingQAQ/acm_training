#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> v(m + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        v[t]++;
    }
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int t;
        cin >> t;
        v[t] = 0;
    }
    for (int i = 1; i <= m; i++) {
        ans += v[i];
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