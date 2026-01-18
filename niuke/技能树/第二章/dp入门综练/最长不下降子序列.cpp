#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <int> a(n + 1);
    a[1] = v[1];
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        int pos = lower_bound(a.begin() + 1, a.begin() + 1 + ans, v[i]) - a.begin();
        a[pos] = v[i];
        if (pos > ans) ans++;
    }

    cout << ans << '\n';
}   
    
signed main ()
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