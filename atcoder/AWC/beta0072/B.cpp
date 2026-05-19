#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1;
    int cur = 0;
    while (r <= k) {
        if (v[r] < 0) {
            cur += v[r];
        }
        r++;
    }
    int al = 1, ar = k;
    int mx = cur;
    while (r <= n) {
        if (v[r] < 0) {
            cur += v[r];
        }
        if (v[l] < 0) {
            cur -= v[l];
        }
        if (cur > mx) {
            al = l + 1;
            ar = r;
            mx = cur;
        }
        r++;
        l++;
    }

    int ans = mx;
    for (int i = 1; i <= n; i++) {
        ans += max(0LL, v[i]);
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