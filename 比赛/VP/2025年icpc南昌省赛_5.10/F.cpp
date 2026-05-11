#include <bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;

void solve ()
{
    int n, k;
    cin >> n >> k;
    ld r0, c0, p, l, r;
    cin >> r0 >> c0 >> p >> l >> r;
    vector <ld> rr (n + 5), cc (n + 5);
    cc[0] = c0;
    rr[0] = r0;

    for (int i = 0; i < k; i ++) {
        int p1;
        ld v1;
        cin >> p1 >> v1;
        rr[p1] = v1;
    }

    ld ans = 0;
    
    // int ok = 1;
    for (int i = n; i >= 0; i --) {
        if (!rr[i]) {
            rr[i] = l;
            // ok ^= 1;
        }
    }

    for (int i = 1; i <= n; i ++) {
        cc[i] = p * cc[i - 1] + (1 - p) * rr[i - 1];
        ans += cc[i] - rr[i];
    }
                                                         
    cout << fixed << setprecision(12) << ans << '\n';
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