#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

class BIT {
    public:
        int n;
        vector <int> bit;

        BIT (int n) {init(n);}

        void init (int m) {
            n = m;
            bit.assign(n + 1, 0);
        }

        int lowbit (int x) { return x & -x; }

        void add (int idx, int diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        int pre (int idx) {
            int res = 0;
            for (; idx > 0; idx -= lowbit(idx)) res += bit[idx];
            return res; 
        }

        int range (int l, int r) {
            if (l > r) return 0;
            return pre(r) - pre(l - 1);
        }
};

void solve ()
{
    int n, m; cin >> n >> m;
    BIT bit(n);

    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        bit.add(i, t);
    }

    while (m--) {
        int a; cin >> a;
        if (a == 1) {
            int c, d; cin >> c >> d;
            bit.add(c, d);
        }else {
            int l, r; cin >> l >> r;
            cout << bit.range(l, r) << '\n';
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