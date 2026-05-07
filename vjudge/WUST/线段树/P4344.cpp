#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        int s, lz;
        int mx, lmx, rmx;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 1, {0, 0, 0, -1, 0, 0, 0});
    }

    void push_up (int p) {
        int L = p << 1, R = p << 1 | 1;
        tr[p].s = tr[L].s + tr[R].s;

        if (tr[L].lmx == tr[L].r - tr[L].l + 1) {
            tr[p].lmx = tr[L].lmx + tr[R].lmx;
        }else {
            tr[p].lmx = tr[L].lmx;
        }
        if (tr[R].rmx == tr[R].r - tr[R].l + 1) {
            tr[p].rmx = tr[R].rmx + tr[L].rmx;
        }else {
            tr[p].rmx = tr[R].rmx;
        }
        tr[p].mx = max({tr[L].mx, tr[R].mx, tr[L].rmx + tr[R].lmx});
    }

    void apply (int p, int op) {
        if (op == 0) {
            tr[p].s = 0;
            tr[p].mx = tr[p].lmx = tr[p].rmx = tr[p].r - tr[p].l + 1;
            tr[p].lz = 0;
        }else if (op == 1) {
            tr[p].s = tr[p].r - tr[p].l + 1;
            tr[p].mx = tr[p].lmx = tr[p].rmx = 0;
            tr[p].lz = 1;
        }
    }

    void push_down (int p) {
        if (tr[p].lz == -1) return;
        apply(p << 1, tr[p].lz);
        apply(p << 1 | 1, tr[p].lz);
        tr[p].lz = -1;
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, r - l + 1, -1, 0, 0, 0};
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, int op) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, op);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, op);
        if (mid < r) modify(p << 1 | 1, l, r, op);
        push_up(p);
    }

    node querylen (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p];
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (r <= mid) return querylen(p << 1, l, r);
        if (l > mid) return querylen(p << 1 | 1, l, r);

        node L = querylen(p << 1, l, r);
        node R = querylen(p << 1 | 1, l, r);
        node res;

        res.l = L.l;
        res.r = R.r;
        res.s = L.s + R.s;
        
        if (L.lmx == L.r - L.l + 1) {
            res.lmx = L.lmx + R.lmx;
        }else {
            res.lmx = L.lmx;
        }
        if (R.rmx == R.r - R.l + 1) {
            res.rmx = R.rmx + L.rmx;
        }else {
            res.rmx = R.rmx;
        }

        res.mx = max({L.mx, R.mx, L.rmx + R.lmx});

        return res;
    }

    int querys (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        int res = 0;
        if (l <= mid) res += querys(p << 1, l, r);
        if (mid < r) res += querys(p << 1 | 1, l, r);
        return res;
    }

    int modify2 (int p, int l, int r, int sum) {
        if (tr[p].r < l || tr[p].l > r || sum == 0) return 0;
        if (l <= tr[p].l && tr[p].r <= r && tr[p].r - tr[p].l + 1 - tr[p].s <= sum) {
            int t = tr[p].r - tr[p].l + 1 - tr[p].s;
            apply(p, 1);
            return t;
        }
        if (tr[p].l == tr[p].r) {
            apply(p, 1);
            return 1;
        }
        push_down(p);
        int res = 0;
        res += modify2(p << 1, l, r, sum);
        res += modify2(p << 1 | 1, l, r, sum - res);
        push_up(p);
        return res;
    }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    SegTree seg(n);
    seg.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int l, r;
            cin >> l >> r;
            seg.modify(1, l, r, 0);
        }else if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.querylen(1, l, r).mx << '\n';
        }else {
            int l0, r0, l1, r1;
            cin >> l0 >> r0 >> l1 >> r1;
            int res = seg.querys(1, l0, r0);
            seg.modify(1, l0, r0, 0);
            seg.modify2(1, l1, r1, res);
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