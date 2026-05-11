#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int mn = 5;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a[i] = v[i];
        mn = min(mn, v[i]);
    }
    
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (v[i] != v[1]) {
            ok = true;
        }
    }

    if (!ok) {
        cout << (mn == 0 ? 0 : 4 - mn) << '\n';
        return;
    }

    int ans = 1e18;
    for (int i = 0; i <= 3; i++) {
        int cur = 0;
        for (int j = 1; j <= n; j++) {
            a[j]++;
            a[j] %= 4;
            cur += a[j];
        }
        int x = (v[1] + cur - a[1]) % 4;
        ans = min(ans, ((x == 0 ? 0 : 4 - x) + cur));
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