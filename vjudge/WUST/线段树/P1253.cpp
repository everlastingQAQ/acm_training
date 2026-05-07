#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = (1LL << 60);

struct SegTree {
    struct node {
        int l, r;
        i64 mx, lz1, lz2;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {0, 0, 0, INF, 0});
    }
    
    void push_up (int p) {
        tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    void apply (int p, i64 x, int op) {
        if (op == 1) {
            tr[p].mx = x;
            tr[p].lz1 = x;
            tr[p].lz2 = 0;
        }else {
            tr[p].mx += x;
            if (tr[p].lz1 != INF) {
                tr[p].lz1 += x; 
            }else {
                tr[p].lz2 += x;
            }
        }
    }

    void push_down (int p) {
        if (tr[p].lz1 != INF) {
            apply(p << 1, tr[p].lz1, 1);
            apply(p << 1 | 1, tr[p].lz1, 1);
            tr[p].lz1 = INF;
        }
        if (tr[p].lz2) {
            apply(p << 1, tr[p].lz2, 2);
            apply(p << 1 | 1, tr[p].lz2, 2);
            tr[p].lz2 = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, INF, 0};
        if (l == r) {
            tr[p].mx = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, i64 t, int op) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, t, op);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, t, op);
        if (mid < r) modify(p << 1 | 1, l, r, t, op);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].mx;
        }
        push_down(p);
        i64 res = -INF;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res = max(res, query(p << 1, l, r));
        if (mid < r) res = max(res, query(p << 1 | 1, l, r));
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
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            i64 x;
            cin >> l >> r >> x;
            seg.modify(1, l, r, x, op);
        }else if (op == 2) {
            int l, r;
            i64 x;
            cin >> l >> r >> x;
            seg.modify(1, l, r, x, op);
        }else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, l, r) << '\n';
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