#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 s, lmx, rmx, mx;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
        tr[p].lmx = max(tr[p << 1].lmx, tr[p << 1].s + tr[p << 1 | 1].lmx);
        tr[p].rmx = max(tr[p << 1 | 1].rmx, tr[p << 1].rmx + tr[p << 1 | 1].s);
        tr[p].mx = max({tr[p << 1].mx, tr[p << 1 | 1].mx, tr[p << 1].rmx + tr[p << 1 | 1].lmx});
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 0, 0};
        if (l == r) {
            tr[p].s = tr[p].lmx = tr[p].rmx = tr[p].mx = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, i64 t) {
        if (tr[p].l == tr[p].r) {
            tr[p].s = tr[p].lmx = tr[p].rmx = tr[p].mx = a[x] = t;
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    node query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p];
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l > mid) return query(p << 1 | 1, l, r);
        if (r <= mid) return query(p << 1, l, r);

        node L = query(p << 1, l, r);
        node R = query(p << 1 | 1, l, r);
        node res;
        res.l = L.l;
        res.r = R.r;
        res.s = L.s + R.s;
        res.lmx = max(L.lmx, L.s + R.lmx);
        res.rmx = max(R.rmx, R.s + L.rmx);
        res.mx = max({L.mx, R.mx, L.rmx + R.lmx});
        return res;
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
            int l, r;
            cin >> l >> r;
            if (l > r) swap(l, r);
            auto t = seg.query(1, l, r);
            cout << t.mx << '\n';
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