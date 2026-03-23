#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

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
            for (; idx > 0; idx -= lowbit(idx)) {
                res = (res + bit[idx]) % mod;
            }
            return res; 
        }

        void point_add (int idx, i64 diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        i64 point_query (int idx) const {
            return sum(idx) - sum(idx - 1);
        }

};

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a[i] = v[i];
    }
    sort(v.begin() + 1, v.end());
    v.erase(unique(v.begin() + 1, v.end()), v.end());
    
    int m = v.size() - 1;
    BIT cnt(m + 5), val(m + 5);
    i64 ans = 1e11;

    for (int i = 1; i <= n; i++) {
        int rk = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        i64 res = val.sum(m) - val.sum(rk + 1) + cnt.
    }
}   
    
int main ()
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