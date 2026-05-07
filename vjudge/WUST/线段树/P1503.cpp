#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        int s, lmx, rmn;
    };

    int n;
    vector <int> a;// 1 -> true
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 1);
        tr.assign(4 * n + 10, {1, -1, -1});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
        if (tr[p << 1].lmx != -1) {
            tr[p].lmx = tr[p << 1].lmx;
        }else {
            tr[p].lmx = tr[p << 1 | 1].lmx;
        }

        if (tr[p << 1 | 1].rmn != -1) {
            tr[p].rmn = tr[p << 1 | 1].rmn;
        }else {
            tr[p].rmn = tr[p << 1].rmn;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 0};
        if (l == r) {
            tr[p].s = 0;
            a[l] = 1;
            tr[p].lmx = tr[p].rmn = -1; 
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, int op) {
        if (tr[p].l == tr[p].r) {
            if (op == 0) {
                a[tr[p].l] = 0;
                tr[p].s = 1;
                tr[p].lmx = tr[p].rmn = tr[p].l;
            }else {
                a[tr[p].l] = 1;
                tr[p].s = 0;
                tr[p].lmx = tr[p].rmn = -1;
            }
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, op);
        else modify(p << 1 | 1, x, op);
        push_up(p);
    }

    int queryr (int p, int l, int r) {
        if (l > tr[p].r || r < tr[p].l || tr[p].s == 0) return -1;
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].lmx;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) {
            int res = queryr(p << 1, l, r);
            if (res != -1) return res;
        } 
        if (mid < r) {
            return queryr(p << 1 | 1, l, r);
        }
        return -1;
    }

    int queryl (int p, int l, int r) {
        if (l > tr[p].r || r < tr[p].l || tr[p].s == 0) return -1;
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].rmn;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (mid < r) {
            int res = queryl(p << 1 | 1, l, r);
            if (res != -1) return res;
        }
        if (l <= mid) {
            return queryl(p << 1, l, r);
        }
        return -1;
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    SegTree seg(n);
    seg.build(1, 1, n);
    vector <int> stk;
    while (q--) {
        char op;
        cin >> op;
        if (op == 'D') {
            int x;
            cin >> x;
            seg.modify(1, x, 0);
            stk.push_back(x);
        }else if (op == 'Q') {
            int x;
            cin >> x;
            if (seg.a[x] == 0) {
                cout << 0 << '\n';
                continue;
            }
            int l = seg.queryl(1, 1, x - 1);
            int r = seg.queryr(1, x + 1, n);
            if (l == -1) l = 0;
            if (r == -1) r = n + 1;
            cout << r - l - 1 << '\n';
        }else {
            if (!stk.empty()) {
                int x;
                x = stk.back();
                stk.pop_back();
                seg.modify(1, x, 1);
            }
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