#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class SegTree {
private:
    int n;
    vector <i64> tr, lz, lzx;

    void push_up (int p) {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }

    void apply (int p, int l, int r, i64 val) {
        tr[p] += val * (r - l + 1);
        lz[p] += val;
        lzx
    }

    void push_down (int p, int l, int r) {
        if (lz[p] == 0) return;
        int mid = (l + r) >> 1;
        apply(p << 1, l, mid, lz[p]);
        apply(p << 1 | 1, mid + 1, r, lz[p]);
        lz[p] = 0;
    }

    void build (int p, int l, int r, const vector <i64> &a) {
        if (l == r) {
            tr[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        push_up(p);
    }

    void modify (int p, int l, int r, int ql, int qr, i64 val) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, val);
            return;
        }
        push_down(p, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(p << 1, l, mid, ql, qr, val);
        if (qr > mid) modify(p << 1 | 1, mid + 1, r, ql, qr, val);
        push_up(p); 
    }

    i64 query (int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tr[p];
        }
        push_down(p, l, r);
        int mid = (l + r) >> 1;
        i64 res = 0;
        if (ql <= mid) res += query(p << 1, l, mid, ql, qr);
        if (qr > mid) res += query(p << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }

public:
    SegTree (int _n = 0) {
        init(_n);
    }

    void init (int _n) {
        n = _n;
        tr.assign(4 * n + 5, 0);
        lz.assign(4 * n + 5, 0);
    }

    void build (const vector <i64> &a) {
        build (1, 1, n, a);
    }

    void modify (int l, int r, i64 val) {
        modify(1, 1, n, l, r, val);
    }

    i64 query (int l, int r) {
        return query(1, 1, n, l, r);
    }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    SegTree seg(n);
    seg.build(v);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            i64 k;
            cin >> x >> y >> k;
            seg.modify(x, y, k);
        }else {
            int x, y;
            cin >> x >> y;
            cout << seg.query(x, y) << '\n';
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