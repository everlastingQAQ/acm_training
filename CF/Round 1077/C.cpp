#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    vector <int> v(n + 1, 0);
    vector <int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a[i] = v[i];
    }

    ranges::sort(a | views::drop(1));
    if (a == v) {
        cout << -1 << '\n';
        return;
    }

    int mx = ranges::max(v | views::drop(1));
    int mn = ranges::min(v | views::drop(1));

    vector <int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = max(v[i] - mn, mx - v[i]);
    }

    int ans = 1e16;
    for (int i = 1; i <= n; i++) {
        if (v[i] != a[i]) ans = min(ans, b[i]);
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