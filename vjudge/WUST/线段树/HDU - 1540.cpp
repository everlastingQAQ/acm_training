#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        int s, lmx, rmn;
    };

    int n;
    vector <int> a;
    vector <node> tr;
    
    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }
    
    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;

        if (tr[p << 1].lmx) tr[p].lmx = tr[p << 1].lmx;
        else tr[p].lmx = tr[p << 1 | 1].lmx;

        if (tr[p << 1 | 1].rmn) tr[p].rmn = tr[p << 1 | 1].rmn;
        else tr[p].rmn = tr[p << 1].rmn;
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 0};
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, int t) {
        if (tr[p].l == tr[p].r) {
            tr[p].s = a[x] = t;
            if (t == 1) {
                tr[p].lmx = tr[p].rmn = x;
            }else {
                tr[p].lmx = tr[p].rmn = 0;
            }
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    int queryl (int p, int l, int r) {
        if (r < tr[p].l || tr[p].r < l || tr[p].s == 0) return -1;
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].lmx ? tr[p].lmx : -1;
        }
        int res = n + 1;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) {
            int ress = queryl(p << 1, l, r);
            if (ress != -1) return ress;
        }
        if (mid < r) {
            return queryl(p << 1 | 1, l, r);
        }
        return -1;
    }

    int queryr (int p, int l, int r) {
        if (r < tr[p].l || tr[p].r < l || tr[p].s == 0) return -1;
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].rmn ? tr[p].rmn : -1;
        }
        int res = -1;
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (mid < r) res = max(res, queryr(p << 1 | 1, l, r));
        if (l <= mid) res = max(res, queryr(p << 1, l, r)); 
        return res;
    }
};

void solve ()
{
    int n, m;
    while (cin >> n >> m) {
        SegTree seg(n);
        seg.build(1, 1, n);
        vector <int> stk;
        for (int i = 1; i <= m; i++) {
            char op;
            cin >> op;
            if (op == 'D') {
                int x;
                cin >> x;
                // if (!seg.a[x]) {
                    stk.push_back(x);
                    seg.modify(1, x, 1);
                // }
            }else if (op == 'Q') {
                int x;
                cin >> x;

                if (seg.a[x]) {
                    cout << 0 << '\n';
                    continue;
                }

                int l = seg.queryr(1, 1, x - 1);
                int r = seg.queryl(1, x + 1, n);
                if (l == -1) l = 0;
                if (r == -1) r = n + 1;
                cout << r - l - 1 << '\n';
            }else {
                if (!stk.empty()) {
                    int x = stk.back();
                    stk.pop_back();
                    seg.modify(1, x, 0);
                }
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