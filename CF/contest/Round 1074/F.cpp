#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, q; cin >> n >> q;
    int N = (1LL << n);
    vector <int> v(N + 1), pre(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] ^ v[i];
    }

    while (q--) {
        int idx, x; cin >> idx >> x;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sz = (1LL << (i - 1));
            int tag = (idx - 1) / sz + 1;

            int aval = pre[sz * (tag - 1)] ^ pre[sz * tag];
            aval ^= v[idx], aval ^= x;
            int bval = ((tag & 1) ? (pre[sz * tag] ^ pre[sz * (tag + 1)]) : (pre[sz * (tag - 2)] ^ pre[sz * (tag - 1)]));

            if (aval < bval || (aval == bval && !(tag & 1))) {
                ans += sz;
            }
        }
        cout << ans << '\n';
    }
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}