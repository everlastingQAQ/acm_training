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
    int n, t; cin >> n >> t;
    int a, b; cin >> a >> b;
    vector <array<int, 2> > v(n);
    for (int i = 0; i < n; i++) cin >> v[i][1];
    for (int i = 0; i < n; i++) cin >> v[i][0];

    int ans1 = 0, ans2 = 0;
    int t1 = 0, t2 = 0;

    for (int i = 0; i < n; i++) {
        if (v[i][0] >= b) {
            if (t1 + 2 * v[i][1] <= t) {
                ans1++;
                t1 += 2 * v[i][1];
            }
        }else {
            if (t1 + v[i][1] <= t) {
                ans1++;
                t1 += v[i][1];
            }
        }
        if (v[i][0] < a) {
            if (t2 + v[i][1] <= t) {
                ans2++;
                t2 += v[i][1];
            }
        }
    }

    cout << ans2 << ' ' << ans1 << '\n';
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