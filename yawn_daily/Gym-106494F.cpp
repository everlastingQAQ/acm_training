#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

i64 xx;

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct SegTree {
    struct node {
        int l, r;
        i64 val;
        bool ok;  
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        if (tr[p << 1].ok && tr[p << 1 | 1].ok && a[tr[p << 1].r] <= a[tr[p << 1 | 1].l]) {
            tr[p].ok = true;
        }else {
            tr[p].ok = false;
        }
        if (tr[p].ok) {
            tr[p].val = (tr[p].r - tr[p].l + 1) % mod;
        }else {
            tr[p].val = (tr[p << 1].val + tr[p << 1 | 1].val) % mod * xx % mod;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].val = 1;
            tr[p].ok = true;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, i64 t) {
        if (tr[p].l == tr[p].r) {
            a[x] = t;
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
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
        int x;
        i64 t;
        cin >> x >> t;
        seg.modify(1, x, t);
        cout << seg.tr[1].val << '\n';
    }
} 

int main ()
{
    xx = qpow(2, mod - 2) % mod;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 