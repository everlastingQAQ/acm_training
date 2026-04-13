#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 s;
    };
    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = max(tr[p << 1].s, tr[p << 1 | 1].s);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) {
            tr[p].s = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    } 

    void modify (int p, int x, i64 t) {
        if (tr[p].l == tr[p].r) {
            tr[p].s = t;
            a[x] = t;
            return; 
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    i64 query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        i64 res = 0;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) res = max(res, query(p << 1, l, r));
        if (r > mid) res = max(res, query(p << 1 | 1, l, r));
        return res;
    }
};

void solve ()
{
    i64 q, mod;
    cin >> q >> mod;
    
    SegTree seg(q);
    int cnt = 1;
    i64 pre = 0;
    seg.build(1, 1, q);

    while (q--) {
        char op;
        cin >> op;
        if (op == 'A') {
            i64 x;
            cin >> x;
            i64 t = (x + pre) % mod;
            seg.modify(1, cnt, t);
            cnt++;
        }else {
            int t;
            cin >> t;
            i64 res = seg.query(1, cnt - t, cnt - 1);
            cout << res << '\n';
            pre = res;
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