#include <bits/stdc++.h>
using namespace std;
#define int long long

class BIT {
    public:
        int n;
        vector <int> bit;
        
        BIT (int n = 0) { init(n); }

        void init (int m) {
            n = m;
            bit.assign(n + 1, 0);
        }

        static int lowbit (int x) { return x & -x; }

        void fastbuild (const vector <int> &v) {
            bit.assign(n + 1, 0);
            for (int i = 1; i <= n; i++) bit[i] = v[i];

            for (int i = 1; i <= n; i++) {
                int j = i + lowbit(i);
                if (j <= n) bit[j] += bit[i];
            }
        }

        int sum (int idx) const {
            int res = 0;
            for (; idx > 0; idx -= lowbit(idx)) {
                res += bit[idx];
            }
            return res;
        }

        void point_add (int idx, int diff) {
            for (; idx <= n; idx += lowbit(idx)) {
                bit[idx] += diff;
            }
        }

        int point_query (int idx) const {
            return sum(idx) - sum(idx - 1);
        }
};

void solve ()
{
    int n, m; cin >> n >> m;
    BIT bit(n);
    while (m--) {
        int op; cin >> op;
        if (op == 0) {
            int l, r; cin >> l >> r;
            bit.point_add(l, 1LL), bit.point_add(r + 1, -1LL);
        }else {
            int t; cin >> t;
            cout << bit.sum(t) << '\n';
        }
    }
}

signed main ()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int _ = 1;
    //cin >> _;
    while (_--) solve();
    return 0;
}