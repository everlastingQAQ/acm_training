#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class BIT {
    public:
        int n;
        vector <i64> bit;

        BIT (int n = 0) {init(n);}
    
        void init (int m) {
            n = m;
            bit.assign(n + 1, 0);
        }

        static i64 lowbit (i64 x) { return x & -x; }

        i64 sum (int idx) const {
            i64 res = 0;
            for (; idx > 0; idx -= lowbit(idx)) res += bit[idx];
            return res; 
        }

        void point_add (int idx, i64 diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        i64 point_query (int idx) const {
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

        i64 pre (i64 x) const {
            if (x <= 0) return 0;
            i64 s1 = B1.sum(x);
            i64 s2 = B2.sum(x);
            return (x + 1) * s1 - s2;
        }

        void range_add (int l, int r, i64 diff) {
            if (l > r) return;
            B1.point_add(l, diff);
            if (r + 1 <= n) B1.point_add(r + 1, -diff);
            B2.point_add(l, diff * l);
            if (r + 1 <= n) B2.point_add(r + 1, -diff * (r + 1));
        }

        i64 range_query (int l, int r) const {
            if (l > r) return 0;
            return pre(r) - pre(l - 1);
        }
};

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    rangeBIT bit(n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((v[i] + bit.range_query(i, i)) % 2 == 1) {
            if (i + k - 1 > n) {
                cout << -1 << '\n';
                return;
            }
            bit.range_add(i, i + k - 1, 1);
            ans++;
        }
    }

    cout << ans << '\n';
} 
    
int main ()
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