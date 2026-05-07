#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q; cin >> n >> q;
    vector <int> v(n + 1), s(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
        d[i] = s[i] - s[i - 1];
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            int diff = v[x + 1] - v[x];
            s[x] = s[x] + diff;
            swap(v[x], v[x + 1]);
        }else {
            int l, r; cin >> l >> r;
            cout << s[r] - s[l - 1] << '\n';
        }
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