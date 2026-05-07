#include <bits/stdc++.h>
using namespace std;
#define int long long
const int  INF = 1e15;

void solve ()
{
    int n; cin >> n;
    vector <int> a (n + 1), pre (n + 1), cur (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        cur[i] = cur[i - 1] + pre[i];
    }
    
    if (pre[n] < 0 || pre[1] < 0) {
        // cerr << pre[n] << ' ' << pre[1] << '\n';
        cout << -1 << '\n';
        return;
    }

    int ans = n, ch = 0, mx = -INF;
    for (int i = 1; i <= n; i ++) {

        // cerr << "i : " << i << ' ' << cur[i] << '\n';
        // cerr << "mx : " << mx << '\n';

        if (cur[i] + ch >= 0) {
            mx = max (mx, pre[i]);
            continue;
        } else {
            if (mx <= 0) {
                cout << -1 << '\n';
                return; 
            }

            int nm = (abs (cur[i] + ch) + mx - 1) / mx;
            ch += nm * mx;
            ans += nm;
        }

        // cerr << "prei : " << pre[i] << '\n';

        mx = max (mx, pre[i]);
    }

    cout << ans << '\n';
} 

int32_t main ()
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