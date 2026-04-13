#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 lmx, rmx, mx, lz;  
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        int L = p << 1, R = p << 1 | 1;

        tr[p].lmx = tr[L].lmx;
        if (tr[L].lmx == tr[L].r - tr[L].l + 1) {
            tr[p].lmx += tr[R].lmx;
        }

        tr[p].rmx = tr[R].rmx;
        if (tr[R].rmx == tr[R].r - tr[R].l + 1) {
            tr[p].rmx += tr[L].rmx;
        }

        tr[p].mx = max({tr[L].mx, tr[R].mx, tr[L].rmx + tr[R].lmx});
    }

    void apply (int p, int val) {
        tr[p].lz = val;
        if (val == 1) {//1 -> empty
            tr[p].lmx = tr[p].rmx = tr[p].mx = tr[p].r - tr[p].l + 1;
        }else {// 0 -> have
            tr[p].lmx = tr[p].rmx = tr[p].mx = 0;
        }
    }

    void push_down (int p) {
        if (tr[p].lz != -1) {
            apply(p << 1, tr[p].lz);   
            apply(p << 1 | 1, tr[p].lz);
            tr[p].lz = -1;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 0, -1};
        if (l == r) {
            tr[p].mx = tr[p].lmx = tr[p].rmx = 1;
            return;
        }
        int mid = (l +r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, int val) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, val);
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, val);
        if (mid < r) modify(p << 1 | 1, l, r, val);
        push_up(p);
    }

    int query (int p, int t) {
        if (tr[p].mx < t) return -1;
        if (tr[p].l == tr[p].r) return tr[p].l;
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (tr[p << 1].mx >= t) {
            return query(p << 1, t);
        }
        if (tr[p << 1].rmx + tr[p << 1 | 1].lmx >= t) {
            return mid - tr[p << 1].rmx + 1;
        }
        return query(p << 1 | 1, t);
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
        if (op == 1) {
            int t;
            cin >> t;
            int x = seg.query(1, t);
            if (x == -1) {
                cout << 0 << '\n';
            }else {
                cout << x << '\n';
                seg.modify(1, x, x + t - 1, 0);
            }
        }else {
            int x, y;
            cin >> x >> y;
            seg.modify(1, x, x + y - 1, 1);
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