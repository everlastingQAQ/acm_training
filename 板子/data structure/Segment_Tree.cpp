#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 s, lz;
    };
    
    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 1);
        tr.assign(4 * n + 10, {0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
    }

    void apply (int p, i64 t) {
        tr[p].s = (tr[p].r - tr[p].l + 1) * t;
        tr[p].lz = t;
    }

    void push_down (int p) {
        if (tr[p].lz) {
            apply(p << 1, tr[p].lz);
            apply(p << 1 | 1, tr[p].lz);
            tr[p].lz = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].s = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, i64 t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, t);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, t);
        if (mid < r) modify(p << 1 | 1, l, r, t);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        i64 res = 0;
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res += query(p << 1, l, r);
        if (mid < r) res += query(p << 1 | 1, l, r);
        return res;
    }
};

void solve ()
{
    
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