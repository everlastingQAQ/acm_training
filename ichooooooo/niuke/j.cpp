#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, p, x;
    cin >> n >> p >> x;
    
    vector <int> a (n);
    int sum = 0;
    for (int & i : a) {
        cin >> i;
        sum += i;
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int now = sum - a[i];
        int nm = (now + 1 + x - 1) / x;
        // cerr << now << ' ' << nm << '\n';
        int mx = (now + p) / x;

        ans += max (0LL, mx - nm + 1);
        if ((now + a[i]) % x == 0 && a[i] >= 1 && a[i] <= p) ans --;
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