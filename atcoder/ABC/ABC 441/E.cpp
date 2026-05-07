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

        void fastbuild (const vector <int> &v) {
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

int Discretize (const vector <int> &a, vector <int> &v, int n)
{
    vector <int> t; t = a;
    ranges::sort(t);
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i <= n; i++) v[i] = lower_bound(t.begin(), t.end(), v[i]) - t.begin() + 1;
    return t.size();
}

void solve ()
{
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    vector <int> t(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') t[i] = 1;
        else if (s[i] == 'B') t[i] = -1;
        else t[i] = 0;
    } 

    vector <int> a(n + 1), v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + t[i];
        v[i] = a[i];
    }

    int m = Discretize(a, v, n);

    BIT bit(m);
    bit.point_add(v[0], 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += bit.sum(v[i] - 1);
        bit.point_add(v[i], 1LL);
    }

    cout << ans << '\n';
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