#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k; cin >> n >> m >> k;
    
    int l = 1, r = m;

    auto check = [&] (int md) -> bool {
        int t = (m - md) / (md + 1);
        int x = m - md - t * (md + 1);
        int sum = (t + 1) * md * n + max(x - 1, 0LL) * n;
        // cout << md << ' ' << t << ' ' << x << ' ' << sum << '\n';
        return sum >= k;
    };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            // cout << "true " << mid << '\n';
            r = mid - 1;
        }else {
            // cout << "false " << mid << '\n';
            l = mid + 1;
        }
    }

    cout << l << '\n';
    
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