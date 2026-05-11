#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;

    for (int len = 0; len <= n; len ++) {
        int ok = 1;
        for (int up = 0; up <= min (len, n - k); up ++) {
            // waimian
            int b1_down = len - up;
            int b2_up = n - k - up;

            if (b1_down != b2_up) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            for (int i = 0; i < len; i ++) {
                cout << 4;
            }

            for (int i = 0; i < n - len; i ++) {
                cout << 1;
            }

            cout << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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