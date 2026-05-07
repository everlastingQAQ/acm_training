#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int t = 0;
    int ans = 0;
    bool ok = true;

    if (n == 0) {
        cout << m << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] > t) ok = true;
        else continue;
        if (ok) {
            ans += v[i] - t;
            t = v[i] + 100;
            ok = false;
        }
    }

    ans += max(0LL, m - t);

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