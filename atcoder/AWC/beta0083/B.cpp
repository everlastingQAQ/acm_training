#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, h;
            cin >> x >> h;
            v[x] = h;
        }else {
            int l, r;
            cin >> l >> r;
            double cur = -1;
            int ans = 0;

            auto cal = [&] (int x) -> double {
                double lmx = 0;
                for (int i = x - 1; i >= 1; i--) {
                    double t = 1.0 * v[i] / (x - i);
                    lmx = max(lmx, t);
                }
                double rmx = 0;
                for (int i = x + 1; i <= n; i++) {
                    double t = 1.0 * v[i] / (i - x);
                    rmx = max(rmx, t);
                }
                double res = 1.0 / (lmx + rmx + 1);
                return res;
            };

            for (int i = l; i <= r; i++) {
                // cout << i << ' ' << cal(i) << '\n';
                if (cal(i) > cur) {
                    ans = i;
                    cur = cal(i);
                }
            }

            cout << ans << '\n';
        }
    }
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