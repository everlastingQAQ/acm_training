#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int l, r, k;
    cin >> l >> r >> k;
    int l1 = l / k, x1 = l % k;
    int r1 = r / k, x2 = r % k;

    if (x2 >= x1) {
        int cnt = r1 - l1 + 1;
        int c1 = (x2 - x1 + 1) * cnt * (cnt - 1) / 2;
        int c2 = ((k - 1) - (x2 - x1 + 1) + 1) * (cnt - 1) * (cnt - 2) / 2;
        int ans = c1 + c2;
        cout << ans << '\n';
    }else {
        int cnt = r1 - l1 + 1;
        int c1 = ((k - 1) - x1 + 1 + x2 - 0 + 1) * (cnt - 1) * (cnt - 2) / 2;
        int c2 = ((x1 - 1) - (x2 + 1) + 1) * (cnt - 2) * (cnt - 3) / 2;
        int ans = c1 + c2;
        cout << ans << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}