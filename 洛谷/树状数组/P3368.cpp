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

        int lowbit (int x) { return x & -x; }

        void fastbuild (const vector <int> &v) {
            bit.assign(n + 1, 0);
            for (int i = 1; i <= n; i++) bit[i] = v[i];
            for (int i = 1; i <= n; i++) {
                int j = i + lowbit(i);
                if (j <= n) bit[j] += bit[i];
            }
        }

        int sum (int idx) {
            int res = 0;
            for (; idx > 0; idx -= lowbit(idx)) res += bit[idx];
            return res; 
        }

        void point_add (int idx, int diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        int point_query (int idx) {
            return sum(idx) - sum(idx - 1);
        }

};

void solve ()
{
    int n, m; cin >> n >> m;
    vector <int> v(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
    }

    BIT bit(n);
    bit.fastbuild(d);

    while (m--) {
        int a; cin >> a;
        if (a == 1) {
            int l, r, k; cin >> l >> r >> k;
            bit.point_add(l, k);
            if (r + 1 <= n) bit.point_add(r + 1, -k);
        }else {
            int x; cin >> x;
            cout << bit.sum(x) << '\n';
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