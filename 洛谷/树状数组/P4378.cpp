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

        BIT (int n = 0) { init(n); }

        void init (int m) {
            n = m;
            bit.assign(n + 1, 0);
        } 

        static int lowbit (int x) { return x & -x; }
        
        int sum (int idx) const {
            int res = 0;
            for (; idx > 0; idx -= lowbit(idx)) {
                res += bit[idx];
            }
            return res;
        }

        void point_add (int idx, int diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        int point_query (int idx) const {
            return sum(idx) - sum(idx - 1);
        }
};

int Discretize (const vector <int> &a, vector <int> &v, int n)
{
    vector <int> t; t = a;
    ranges::sort(t | views::drop(1));
    t.erase(unique(t.begin() + 1, t.end()), t.end());
    for (int i = 1; i <= n; i++) {
        v[i] = lower_bound(t.begin() + 1, t.end(), v[i]) - t.begin();
    }
    return t.size() - 1;
}

void solve ()
{
    int n; cin >> n;
    vector <int> a(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], v[i] = a[i];

    int m = Discretize(a, v, n);
    BIT bit(m);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max((i - 1) - bit.sum(v[i]), ans);
        bit.point_add(v[i], 1LL);
    }   

    cout << ans + 1 << '\n';
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