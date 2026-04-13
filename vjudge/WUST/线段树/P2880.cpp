#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 mx, mn;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 1, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
        tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].mx = a[l];
            tr[p].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    array <i64, 2> query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return {tr[p].mx, tr[p].mn};
        }
        i64 a1 = -1, a2 = 1e9;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) {
            auto [x, y] = query(p << 1, l, r);
            a1 = max(a1, x);
            a2 = min(a2, y);
        }
        if (r > mid) {
            auto [x, y] = query(p << 1 | 1, l, r);
            a1 = max(a1, x);
            a2 = min(a2, y);
        }
        return {a1, a2};
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
        int l, r;
        cin >> l >> r;
        auto [x, y] = seg.query(1, l, r);
        cout << x - y << '\n';
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