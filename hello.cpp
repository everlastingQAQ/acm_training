#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n, m, p;
    cin >> n >> m >> p;
    int mx = -1;
    int x, y, z;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= p; k++) {
                int t;
                cin >> t;
                if (t > mx) {
                    mx = t;
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }
    int l1 = max(x - 1, n - x), l2 = max(y - 1, m - y), l3 = max(z - 1, p - z);
    int cur = sqrtl(l1 * l1 + l2 * l2 + l3 * l3);
    if (cur * cur != l1 * l1 + l2 * l2 + l3 * l3) cur++;
    cout << cur << '\n';
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