#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 sum;
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
        tr[p].sum = max(tr[p << 1].sum, tr[p << 1 | 1].sum);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) {
            tr[p].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p); 
    }

    void modify (int p, int x, i64 t) {
        if (tr[p].l == tr[p].r) {
            tr[p].sum = max(tr[p].sum, t);
            a[x] = max(a[x], t);
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].sum;
        }
        i64 res = 0;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res = max(res, query(p << 1, l, r));
        if (r > mid) res = max(res, query(p << 1 | 1, l ,r));
        return res;
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, n);
    while (q--) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, l, r) << '\n';
        }else {
            int x;
            i64 t;
            cin >> x >> t;
            seg.modify(1, x, t);
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