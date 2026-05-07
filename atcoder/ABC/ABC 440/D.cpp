#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n, q; cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    ranges::sort(v | views::drop(1));

    while (q--) {
        int x, y; cin >> x >> y;
        int pos = ranges::lower_bound(v | views::drop(1), x) - v.begin();
        int l = x, r = 1e17;

        auto check = [&] (int mid) -> bool {
            int cnt = mid - x + 1;
            cnt -= ranges::upper_bound(v | views::drop(1), mid) - v.begin() - pos;
            return cnt >= y;
        };

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
}   

signed main ()
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