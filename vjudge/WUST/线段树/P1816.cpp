#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 s;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = min(tr[p << 1].s, tr[p << 1 | 1].s);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) {
            tr[p].s = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        i64 res = 1e11;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res = min(res, query(p << 1, l, r));
        if (r > mid) res = min(res, query(p << 1 | 1, l, r));
        return res;
    }
};

void solve ()
{
    int m, n;
    cin >> m >> n;
    SegTree seg(m);
    for (int i = 1; i <= m; i++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, m);
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << seg.query(1, l, r) << ' ';
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