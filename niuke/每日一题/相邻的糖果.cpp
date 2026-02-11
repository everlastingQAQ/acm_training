#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m, x;
    cin >> n >> m >> x;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int cur = 0;
    int ans = 0;
    int l = 1, r = 1;
    while (r <= min(m, n)) {
        cur += v[r];
        r++;
    }

    r = m;
    while (r >= 1 && cur > x) {
        cur -= v[r];
        if (cur < x) {
            cur += v[r];
            v[r] -= cur - x;
            ans += cur - x;
            cur = x;
            break;
        }
        ans += v[r];
        v[r] = 0;
        r--;
    }

    for (int i = m + 1; i <= n; i++) {
        cur -= v[i - m];
        cur += v[i];
        if (cur > x) {
            int t = cur - x;
            v[i] -= t;
            ans += t;
            cur = x;
        }
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