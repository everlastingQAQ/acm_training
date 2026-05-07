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
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        int L = p << 1, R = p << 1 | 1;
        tr[p].s = tr[L].s + tr[R].s;
        if (tr[L].lmx0 == tr[L].r - tr[L].l + 1) {
            tr[p].lmx0 = tr[L].lmx0 + tr[R].lmx0;
        }else {
            tr[p].lmx0 = tr[L].lmx0;
        }
        if (tr[R].rmx0 == tr[R].r - tr[R].l + 1) {
            tr[p].rmx0 = tr[R].rmx0 + tr[L].rmx0;
        }else {
            tr[p].rmx0 = tr[R].rmx0;
        }
        tr[p].mx0 = max({tr[L].mx0, tr[R].mx0, tr[L].rmx0 + tr[R].lmx0});

        if (tr[L].lmx1 == tr[L].r - tr[L].l + 1) {
            tr[p].lmx1 = tr[L].lmx1 + tr[R].lmx1;
        }else {
            tr[p].lmx1 = tr[L].lmx1;
        }
        if (tr[R].rmx1 == tr[R].r - tr[R].l + 1) {
            tr[p].rmx1 = tr[R].rmx1 + tr[L].rmx1;
        }else {
            tr[p].rmx1 = tr[R].rmx1;
        }
        tr[p].mx1 = max({tr[L].mx1, tr[R].mx1, tr[L].rmx1 + tr[R].lmx1});
    }

    void apply (int p) {
        tr[p].s = tr[p].r - tr[p].l + 1 - tr[p].s;
        swap(tr[p].lmx0, tr[p].lmx1);
        swap(tr[p].rmx0, tr[p].rmx1);
        swap(tr[p].mx0, tr[p].mx1);
        tr[p].lz ^= 1;
    }

    void push_down (int p) {
        if (tr[p].lz) {
            apply(p << 1);
            apply(p << 1 | 1);
            tr[p].lz = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 0, 0, 0, 0};
        if (l == r) {
            tr[p].s = a[l];
            if (tr[p].s == 1) {
                tr[p].lmx1 = tr[p].rmx1 = 1;
                tr[p].lmx0 = tr[p].rmx0 = 0;
                tr[p].mx0 = 0;
                tr[p].mx1 = 1;
            }else {
                tr[p].lmx1 = tr[p].rmx1 = 0;
                tr[p].lmx0 = tr[p].rmx0 = 1;
                tr[p].mx0 = 1;
                tr[p].mx1 = 0;
            }
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r);
        if (mid < r) modify(p << 1 | 1, l, r);
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

        node res;
        node L = query(p << 1, l, r);
        node R = query(p << 1 | 1, l, r);
        res.s = L.s + R.s;
        res.l = L.l;
        res.r = R.r;

        if (L.lmx0 == L.r - L.l + 1) {
            res.lmx0 = L.lmx0 + R.lmx0;
        }else {
            res.lmx0 = L.lmx0;
        }
        if (R.lmx0 == R.r - R.l + 1) {
            res.rmx0 = R.rmx0 + L.rmx0;
        }else {
            res.rmx0 = R.rmx0;
        }
        res.mx0 = max({L.mx0, R.mx0, L.rmx0 + R.lmx0});

        if (L.lmx1 == L.r - L.l + 1) {
            res.lmx1 = L.lmx1 + R.lmx1;
        }else {
            res.lmx1 = L.lmx1;
        }
        if (R.lmx1 == R.r - R.l + 1) {
            res.rmx1 = R.rmx1 + L.rmx1;
        }else {
            res.rmx1 = R.rmx1;
        }
        res.mx1 = max({L.mx1, R.mx1, L.rmx1 + R.lmx1});

        return res;
    }
};

void solve ()
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' + s;
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        seg.a[i] = s[i] - '0';
    }
    seg.build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            seg.modify(1, l, r);
        }else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, l, r).mx1 << '\n';
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