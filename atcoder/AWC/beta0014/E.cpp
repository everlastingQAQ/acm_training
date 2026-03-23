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

        BIT (int n = 0) {init(n);}

        void init (int m) {
            n = m;
            bit.assign(n + 1, 0);
        }

        static int lowbit (int x) { return x & -x; }

        void fastbuild (const vector <int> &v) {//1-based
            bit.assign(n + 1, 0);
            for (int i = 1; i <= n; i++) bit[i] = v[i];
            for (int i = 1; i <= n; i++) {
                int j = i + lowbit(i);
                if (j <= n) bit[j] += bit[i];
            }
        }

        int sum (int idx) const {
            int res = 0;
            for (; idx > 0; idx -= lowbit(idx)) res += bit[idx];
            return res; 
        }

        void point_add (int idx, int diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        int point_query (int idx) const {
            return sum(idx) - sum(idx - 1);
        }

};

class rangeBIT {
    public:
        int n; 
        BIT B1, B2;

        rangeBIT (int n = 0) { init(n); }
         
        void init (int m) {
            n = m;
            B1.init(n);
            B2.init(n);
        }

        int pre (int x) const {
            if (x <= 0) return 0;
            int s1 = B1.sum(x);
            int s2 = B2.sum(x);
            return (x + 1) * s1 - s2;
        }

        void range_add (int l, int r, int diff) {
            if (l > r) return;
            B1.point_add(l, diff);
            if (r + 1 <= n) B1.point_add(r + 1, -diff);
            B2.point_add(l, diff * l);
            if (r + 1 <= n) B2.point_add(r + 1, -diff * (r + 1));
        }

        int range_query (int l, int r) const {
            if (l > r) return 0;
            return pre(r) - pre(l - 1);
        }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    rangeBIT bit(n);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        bit.range_add(i, i, t);
    }
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, diff;
            cin >> l >> r >> diff;
            bit.range_add(l, r, diff);
        }else {
            int l, r;
            cin >> l >> r;
            cout << bit.range_query(l, r) << '\n';
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