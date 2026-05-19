#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    multiset <int> stx, sty;
    set <int> vx, vy;
    vx.insert(0);
    vx.insert(n);
    vy.insert(0);
    vy.insert(m);
    stx.insert(n);
    sty.insert(m);

    for (int i = 1; i <= q; i++) {
        int op, k;
        cin >> op >> k;
        if (op == 1) {
            int l = *(--vx.lower_bound(k));
            int r = *(vx.upper_bound(k));
            int len = r - l;
            int x1 = k - l;
            int x2 = r - k;
            stx.erase(stx.find(len));
            stx.insert(x1);
            stx.insert(x2);
            vx.insert(k);
        }else {
            int l = *(--vy.lower_bound(k));
            int r = *(vy.upper_bound(k));
            int len = r - l;
            int x1 = k - l;
            int x2 = r - k;
            sty.erase(sty.find(len));
            sty.insert(x1);
            sty.insert(x2);
            vy.insert(k);
        }
        int ans = (*stx.rbegin()) * (*sty.rbegin());
        cout << ans << '\n';
    }
}

signed main()
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