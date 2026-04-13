#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 s, lz, mx;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 1, {0, 0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
        tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    void apply (int p, i64 t) {
        tr[p].s += (tr[p].r - tr[p].l + 1) * t;
        tr[p].lz += t;
        tr[p].mx += t;
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
            tr[p].mx = a[l];
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
            return tr[p].mx;
        }
        push_down(p);
        i64 res = 0;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res = max(res, query(p << 1, l, r));
        if (mid < r) res = max(res, query(p << 1 | 1, l, r));
        return res;
    }
};

void solve ()
{
    int n, k;
    cin >> n >> k;
    SegTree seg(n + 5);
    seg.build(1, 1, n);

    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    int ans = 0;
    int l = 1, r = 1;
    int cur = 0;
    while (r <= n) {
        seg.modify(1, v[r][0], v[r][1], 1);
        cur++;
        while (l < r && seg.query(1, 1, n) > k) {
            seg.modify(1, v[l][0], v[l][1], -1);
            l++;
            cur--;
        }
        ans = max(ans, cur);
        r++;
    }
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}