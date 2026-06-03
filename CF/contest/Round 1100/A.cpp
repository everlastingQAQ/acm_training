#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    int mx = -1, mn = 1e18;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        mx = max(mx, t);
        mn = min(mn, t);
    }
    cout << (mx - mn + 1) / 2 << '\n';
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