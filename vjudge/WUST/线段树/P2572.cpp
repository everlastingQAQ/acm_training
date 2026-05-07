#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        int s, lz;
        int lmx0, rmx0, mx0;
        int lmx1, rmx1, mx1;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 5, {0, 0, 0, -1, 0, 0, 0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
        
        if (tr[p << 1].lmx0 == tr[p << 1].r - tr[p << 1].l + 1) {
            tr[p].lmx0 = tr[p << 1].lmx0 + tr[p << 1 | 1].lmx0;
        }else {
            tr[p].lmx0 = tr[p << 1].lmx0;
        }
        if (tr[p << 1 | 1].rmx0 == tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1) {
            tr[p].rmx0 = tr[p << 1 | 1].rmx0 + tr[p << 1].rmx0;
        }else {
            tr[p].rmx0 = tr[p << 1 | 1].rmx0;
        }
        tr[p].mx0 = max({tr[p << 1].mx0, tr[p << 1 | 1].mx0, tr[p << 1].rmx0 + tr[p << 1 | 1].lmx0});

        if (tr[p << 1].lmx1 == tr[p << 1].r - tr[p << 1].l + 1) {
            tr[p].lmx1 = tr[p << 1].lmx1 + tr[p << 1 | 1].lmx1;
        }else {
            tr[p].lmx1 = tr[p << 1].lmx1;
        }
        if (tr[p << 1 | 1].rmx1 == tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1) {
            tr[p].rmx1 = tr[p << 1 | 1].rmx1 + tr[p << 1].rmx1;
        }else {
            tr[p].rmx1 = tr[p << 1 | 1].rmx1;
        }
        tr[p].mx1 = max({tr[p << 1].mx1, tr[p << 1 | 1].mx1, tr[p << 1].rmx1 + tr[p << 1 | 1].lmx1});
        
    }

    void apply0 (int p) {
        tr[p].s = 0;
        tr[p].lmx1 = 0;
        tr[p].rmx1 = 0;
        tr[p].mx1 = 0;
        tr[p].lmx0 = tr[p].r - tr[p].l + 1;
        tr[p].rmx0 = tr[p].r - tr[p].l + 1;
        tr[p].mx0 = tr[p].r - tr[p].l + 1;
        tr[p].lz = 0;
    }

    void apply1 (int p) {
        tr[p].s = tr[p].r - tr[p].l + 1;
        tr[p].lmx1 = tr[p].s;
        tr[p].rmx1 = tr[p].s;
        tr[p].mx1 = tr[p].s;
        tr[p].lmx0 = 0;
        tr[p].rmx0 = 0;
        tr[p].mx0 = 0;
        tr[p].lz = 1;
    }

    void apply2 (int p) {
        swap(tr[p].lmx0, tr[p].lmx1);
        swap(tr[p].rmx0, tr[p].rmx1);
        swap(tr[p].mx0, tr[p].mx1);
        tr[p].s = tr[p].r - tr[p].l + 1 - tr[p].s;

        if (tr[p].lz == -1) tr[p].lz = 2;
        else if (tr[p].lz == 0) tr[p].lz = 1;
        else if (tr[p].lz == 1) tr[p].lz = 0;
        else if (tr[p].lz == 2) tr[p].lz = -1;
    }

    void push_down (int p) {
        if (tr[p].lz == -1) return;
        if (tr[p].lz == 2) {
            apply2(p << 1);
            apply2(p << 1 | 1);
            tr[p].lz = -1;
        }else if (tr[p].lz == 1) {
            apply1(p << 1);
            apply1(p << 1 | 1);
            tr[p].lz = -1;
        }else if (tr[p].lz == 0) {
            apply0(p << 1);
            apply0(p << 1 | 1);
            tr[p].lz = -1;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, -1, 0, 0, 0, 0, 0, 0};
        if (l == r) {
            tr[p].s = a[l];
            if (a[l] == 0) {
                tr[p].lmx0 = 1;
                tr[p].rmx0 = 1;
                tr[p].mx0 = 1;
            }else {
                tr[p].lmx1 = 1;
                tr[p].rmx1 = 1;
                tr[p].mx1 = 1;
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, int op) {
        if (l <= tr[p].l && tr[p].r <= r) {
            if (op == 0) apply0(p);
            else if (op == 1) apply1(p);
            else if (op == 2) apply2(p);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, op);
        if (mid < r) modify(p << 1 | 1, l, r, op);
        push_up(p);
    }

    node query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p];
        }
        push_down(p);

        int mid = (tr[p].l + tr[p].r) >> 1;
        if (r <= mid) return query(p << 1, l, r);
        if (l > mid) return query(p << 1 | 1, l, r);

        node L = query(p << 1, l, r);
        node R = query(p << 1 | 1, l, r);

        node res;
        res.l = L.l;
        res.r = R.r;
        res.lz = -1;
        res.s = L.s + R.s;
    
        res.lmx1 = L.lmx1;
        if (L.lmx1 == L.r - L.l + 1) {
            res.lmx1 += R.lmx1;
        }
        res.rmx1 = R.rmx1;
        if (R.rmx1 == R.r - R.l + 1) {
            res.rmx1 += L.rmx1;
        }
        res.mx1 = max({L.mx1, R.mx1, L.rmx1 + R.lmx1});

        res.lmx0 = L.lmx0;
        if (L.lmx0 == L.r - L.l + 1) {
            res.lmx0 += R.lmx0;
        }
        res.rmx0 = R.rmx0;
        if (R.rmx0 == R.r - R.l + 1) {
            res.rmx0 += L.rmx0;
        }
        res.mx0 = max({L.mx0, R.mx0, L.rmx0 + R.lmx0});

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
        int op, l, r;
        cin >> op >> l >> r;
        if (op <= 2) {
            seg.modify(1, l + 1, r + 1, op);
        }else if (op == 3) {
            cout << seg.query(1, l + 1, r + 1).s << '\n';
        }else if (op == 4) {
            cout << seg.query(1, l + 1, r + 1).mx1 << '\n';
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