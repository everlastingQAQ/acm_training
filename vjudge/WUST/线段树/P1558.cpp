#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 mask, lz;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 1);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        tr[p].mask = tr[p << 1].mask | tr[p << 1 | 1].mask;
    }

    void apply (int p, i64 t) {
        tr[p].mask = t;
        tr[p].lz = t;
    }

    void push_down (int p) {
        if (tr[p].lz != 0) {
            apply(p << 1, tr[p].lz);
            apply(p << 1 | 1, tr[p].lz);
            tr[p].lz = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].mask = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, i64 x) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, x);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, x);
        if (mid < r) modify(p << 1 | 1, l, r, x);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].mask;
        }
        push_down(p);
        i64 res = 0;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res |= query(p << 1, l, r);
        if (mid < r) res |= query(p << 1 | 1, l, r);
        return res;
    }
};

void solve ()
{
    int n, t, o;
    cin >> n >> t >> o;
    SegTree seg(n);
    seg.build(1, 1, n);
    while (o--) {
        char c;
        cin >> c;
        if (c == 'C') {
            int a, b;
            i64 c;
            cin >> a >> b >> c;
            if (a > b) swap(a, b);
            i64 mask = (1LL << (c - 1));
            seg.modify(1, a, b, mask);
        }else {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            i64 res = seg.query(1, a, b);
            i64 ans = __builtin_popcountll(res);
            cout << ans << '\n';
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