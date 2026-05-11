#include <bits/stdc++.h>
using namespace std;
#define int long long

struct PSegTree {
    struct node {
        int ls, rs;
        int s;
    };

    int n;
    vector <int> a;
    vector <node> tr;
    vector <int> rt;

    PSegTree (int n = 0, int m = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.reserve(2 * n + (m + 5) * 25);
        tr.push_back({0, 0, 0});
        rt.assign(m + 1, 0);
    }

    int nw () {
        tr.push_back({0, 0, 0});
        return tr.size() - 1;
    }

    int clone (int p) {
        tr.push_back(tr[p]);
        return tr.size() - 1;
    }

    void push_up (int p) {
        tr[p].s = tr[tr[p].ls].s + tr[tr[p].rs].s;
    }

    int build (int l, int r) {
        int p = nw();
        if (l == r) {
            tr[p].s = a[l];
            return p;
        }
        int mid = l + ((r - l) >> 1);
        tr[p].ls = build(l, mid);
        tr[p].rs = build(mid + 1, r);
        push_up(p);
        return p;
    }
    
    int modify (int p, int l, int r, int x, int t) {
        int q = clone(p);
        if (l == r) {
            tr[q].s = t;
            return q;
        }
        int mid = l + ((r - l) >> 1);
        if (x <= mid) {
            tr[q].ls = modify(tr[p].ls, l, mid, x, t);
        }else {
            tr[q].rs = modify(tr[p].rs, mid + 1, r, x, t);
        }
        push_up(q);
        return q;
    }

    int query (int p, int l, int r, int ql, int qr) {
        if (!p || l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return tr[p].s;
        int mid = l + ((r - l) >> 1);
        int res = 0;
        if (ql <= mid) {
            res += query(tr[p].ls, l, mid, ql, qr);
        }
        if (mid < qr) {
            res += query(tr[p].rs, mid + 1, r, ql, qr);
        }
        return res;
    }

};

void solve ()
{
    int n, q;
    cin >> n >> q;
    PSegTree seg(n, q);
    for (int i = 1; i <= n; i++) {
        cin >> seg.a[i];
    }
    seg.rt[0] = seg.build(1, n);
    for (int i = 1; i <= q; i++) {
        int v, op;
        cin >> v >> op;
        if (op == 1) {
            int x, t;
            cin >> x >> t;
            seg.rt[i] = seg.modify(seg.rt[v], 1, n, x, t);
        }else {
            int p;
            cin >> p;
            cout << seg.query(seg.rt[v], 1, n, p, p) << '\n';
            seg.rt[i] = seg.rt[v];
        }
    }
}

int32_t main () 
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