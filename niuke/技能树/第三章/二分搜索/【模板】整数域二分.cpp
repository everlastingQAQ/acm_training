#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, q; cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());

    while (q--) {
        int l, r; cin >> l >> r;
        cout << upper_bound(v.begin() + 1, v.end(), r) - lower_bound(v.begin() + 1, v.end(), l) << '\n';
    }
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