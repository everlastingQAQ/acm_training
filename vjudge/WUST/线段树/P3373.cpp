#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int mod;

struct SegTree {
    struct node {
        int l, r;
        i64 s, p, m;
    };
    
    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {0, 0, 0, 0, 1});
    }

    void push_up (int p) {
        tr[p].s = (tr[p << 1].s + tr[p << 1 | 1].s) % mod;
    }

    void apply (int p, i64 mul, i64 add) {
        int len = tr[p].r - tr[p].l + 1;
        tr[p].s = (tr[p].s * mul % mod + len * add % mod) % mod;
        tr[p].p = (tr[p].p * mul % mod + add) % mod;
        tr[p].m = tr[p].m * mul % mod;
    }

    void push_down (int p) {
        if (tr[p].p != 0 || tr[p].m != 1) {
            apply(p << 1, tr[p].m, tr[p].p);
            apply(p << 1 | 1, tr[p].m, tr[p].p);
            tr[p].m = 1;
            tr[p].p = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 1};
        if (l == r) {
            tr[p].s = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify_add (int p, int l, int r, i64 t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, 1, t);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify_add(p << 1, l, r, t);
        if (mid < r) modify_add(p << 1 | 1, l, r, t);
        push_up(p);
    }

    void modify_mul (int p, int l, int r, i64 t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, t, 0);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify_mul(p << 1, l, r, t);
        if (mid < r) modify_mul(p << 1 | 1, l, r, t);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        push_down(p);
        i64 res = 0;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res = (res + query(p << 1, l, r)) % mod;
        if (mid < r) res = (res + query(p << 1 | 1, l, r)) % mod;
        return res;
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q >> mod;
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            seg.modify_mul(1, l, r, k);
        }else if (op == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            seg.modify_add(1, l, r, k);
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