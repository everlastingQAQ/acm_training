#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, t;
    cin >> n >> t;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    auto check = [&] (int x) -> bool {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += x / v[i];
            if (res >= t) return true;
        }
        return res >= t;
    };

    int l = 0, r = 1e18;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
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