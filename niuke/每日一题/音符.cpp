#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, q; cin >> n >> q;
    vector <int> v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    while (q--) {
        int t; cin >> t;
        int pos = upper_bound(pre.begin() + 1, pre.end(), t) - pre.begin();
        cout << pos << '\n';
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