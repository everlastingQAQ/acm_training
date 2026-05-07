#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class SegTree {
private:
    int n;
    vector <i64> tr;

    void push_up (int p) {
        tr[p] = max(tr[p << 1],  tr[p << 1 | 1]);
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

    void modify (int p, int l, int r, int x, i64 val) {
        if (l == r) {
            tr[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) {
            modify(p << 1, l, mid, x, val);
        }else {
            modify(p << 1 | 1, mid + 1, r, x, val);
        }
        push_up(p);
    }

    i64 query (int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tr[p];
        }
        int mid = (l + r) >> 1;
        i64 res = LLONG_MIN;
        if (ql <= mid) {
            res = max(res, query(p << 1, l, mid, ql, qr));
        }
        if (qr > mid) {
            res = max(res, query(p << 1 | 1, mid + 1, r, ql, qr));
        }
        return res;
    }
public:
    SegTree (int _n = 0) {
        init(_n);
    }

    void init (int _n) {
        n = _n;
        tr.assign(4 * n + 5, 0);
    }

    void build (const vector <i64> &a) {
        build(1, 1, n, a);
    }
    
    void modify (int x, i64 val) {
        modify(1, 1, n, x, val);
    }

    i64 query (int l, int r) {
        return query(1, 1, n, l, r);
    }
};

void solve ()
{
    int m, d;
    cin >> m >> d;
    SegTree seg(m);
    int cnt = 0;
    i64 t = 0;
    
    while (m--) {
        char op;
        cin >> op;
        if (op == 'A') {
            i64 x;
            cin >> x;
            i64 cur = (x + t) % d;
            cnt++;
            seg.modify(cnt, cur); 
        }else {
            int l;
            cin >> l;
            cout << seg.query(cnt - l + 1, cnt) << '\n';
            t = seg.query(cnt - l + 1, cnt);
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