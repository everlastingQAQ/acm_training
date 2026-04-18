#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 k, d;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 5, {});
    }

    void apply (int p, i64 k, i64 d) {
        tr[p].k += k;
        tr[p].d += d;
    }

    void push_down (int p) {
        if (tr[p].k == 0 && tr[p].d == 0) return;
        int l = tr[p].l, r = tr[p].r;
        int mid = (l + r) >> 1;
        apply(p << 1, tr[p].k, tr[p].d);
        apply(p << 1 | 1, tr[p].k + (mid - l + 1) * tr[p].d, tr[p].d);
        tr[p].k = 0;
        tr[p].d = 0;
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
    }

    void modify (int p, int l, int r, i64 k, i64 d) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, k + (tr[p].l - l) * d, d);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, k, d);
        if (mid < r) modify(p << 1 | 1, l, r, k, d);
    }

    i64 query (int p, int pos) {
        if (tr[p].l == tr[p].r) {
            return a[pos] + tr[p].k;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (pos <= mid) return query(p << 1, pos);
        else return query(p << 1 | 1, pos);
    }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            seg.modify(1, l, r, k, d);
        }else {
            int p;
            cin >> p;
            cout << seg.query(1, p) << '\n'; 
        }
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