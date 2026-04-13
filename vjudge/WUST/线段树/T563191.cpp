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
        int L = p << 1, R = p << 1 | 1;
        tr[p].s = tr[L].s + tr[R].s;
        tr[p].lmx = max(tr[L].lmx, tr[L].s + tr[R].lmx);
        tr[p].rmx = max(tr[R].rmx, tr[R].s + tr[L].rmx);
        tr[p].mx = max({tr[L].mx, tr[R].mx, tr[L].rmx + tr[R].lmx});
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

        node res;
        node L = query(p << 1, l, r);
        node R = query(p << 1 | 1, l, r);
        res.s = L.s + R.s;
        res.l = L.l;
        res.r = R.r;
        res.lmx = max(L.lmx, L.s + R.lmx);
        res.rmx = max(R.rmx, R.s + L.rmx);
        res.mx = max({L.mx, R.mx, L.rmx + R.lmx});
        return res;
    }
};

void solve ()
{
    int n;
    cin >> n;
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, n);
    int q;
    cin >> q;

    auto kk = seg.query(1, 1, n);
    cout << kk.mx << '\n';
    while (q--) {
        int x;
        i64 t;
        cin >> x >> t;
        seg.modify(1, x, t);
        auto k = seg.query(1, 1, n);
        cout << k.mx << '\n';
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