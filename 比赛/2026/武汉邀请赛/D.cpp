#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    int l1 = 2;
    while (l1 <= n) {
        l1 *= 2;
    }
    int l2 = 3;
    while (l2 <= n) {
        l2 *= 3;
    }

    int ans = 0;
    while (n > 1) {
        int mx = n * 2 - 1;
        while (l2 > 3 && l2 > mx) {
            l2 /= 3;
        }
        while (l1 > 2 && l1 > mx) {
            l1 /= 2;
        }
        int cur = 1;
        int l3 = 1;
        while (cur < n) {
            cur *= 2;
            int t = cur;
            while (t * 3 <= mx) {
                t *= 3;
            }
            if (t >= n) {
                l3 = max(l3, t);
            }
        }
        n = max({l1 / 2, l2 / 3, l3 / 3});
        ans++;
    }

    cout << ans << '\n';
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