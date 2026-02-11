#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int ans = 0;
    vector <int> mn(n + 1, 1e18), mx(n + 1, -1e18);
    for (int i = 1; i <= n; i++) {
        if (i & 1) ans += v[i];
        else ans -= v[i];
    }
    int cur = ans;
    if (n & 1) ans += n - 1;
    else ans += n - 2;
    // cout << ans << '\n';
    
    mn[1] = 1 + 2 * v[1];
    for (int i = 2; i <= n; i++) {
        if (i & 1) mn[i] = min(mn[i - 2], i + 2 * v[i]);
        else mx[i] = max(mx[i - 2], 2 * v[i] - i);
    }

    for (int i = 1; i <= n; i++) {
        if (i & 1) ans = max(ans, cur + mx[i - 1] - 2 * v[i] + i);
        else ans = max(ans, cur + 2 * v[i] - mn[i - 1] + i);
    }

    cout << ans << '\n';
}   
    
int32_t main ()
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