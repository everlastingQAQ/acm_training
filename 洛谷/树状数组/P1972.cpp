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

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int q;
    cin >> q;
    vector <array <int, 3> > a(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin() + 1, a.end(), [] (auto a, auto b) {
        return a[1] < b[1];
    });

    BIT bit(n);
    map <int, int> vis;
    vector <int> ans(q + 1);

    for (int i = 1; i <= q; i++) {
        for (int j = a[i - 1][1] + 1; j <= a[i][1]; j++) {
            if (vis[v[j]]) {
                bit.point_add(vis[v[j]], -1);
            }
            vis[v[j]] = j;
            bit.point_add(j, 1);
        }
        int cur = bit.sum(a[i][1]) - bit.sum(a[i][0] - 1);
        ans[a[i][2]] = cur;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
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