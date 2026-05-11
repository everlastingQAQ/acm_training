#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    bool ok = false;
    vector <int> v(n + 1);
    int mx = -1e18;
    int mn = 1e18;
    int sum = 0;
    bool ok1 = false, ok2 = false;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] < 0) ok1 = true;
        if (v[i] >= 0) ok2 = true;
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
        sum += llabs(v[i]);
    }

    if (n == 1) {
        cout << v[1] << '\n';
        return; 
    }

    if (ok1 && ok2) {
        cout << sum << '\n';
    }
    else if (!ok1 && ok2) {
        cout << sum - mn - mn << '\n';
    }
    else if (ok1 && !ok2) {
        cout << sum + mx + mx << '\n';
    }

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