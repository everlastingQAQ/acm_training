#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    auto cal = [&] (int idx) -> void {
        int res = 0;
        int mx = v[idx];

        vector <int> suf(n + 2, 0);
        for (int i = idx - 1; i >= 1; i--) {
            suf[i] = max(suf[i + 1], v[i]);
        }
        suf[n + 1] = suf[1];
        for (int i = n; i > idx; i--) {
            suf[i] = max(suf[i + 1], v[i]);
        }

        int ii = idx + 1;
        if (ii == n + 1) ii = 1;

        for (int i = ii; ; i++) {
            if (i == idx) {
                break;
            }

            if (i == n + 1) {
                i = 0;
                continue;
            }

            if (v[i] > mx) {
                res += mx;
                mx = v[i];
            }else {
                res += min(mx, suf[i]);
            }
        }

        cout << res << ' ';

    };

    for (int i = 1; i <= n; i++) {
        cal(i);
    }
    cout << '\n';
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