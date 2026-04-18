#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;

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
        i64 z, o;
    };
    
    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int _n = 0) {
        n = _n;
        a.assign(n + 1, 1);
        tr.assign(4 * n + 10, {0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].z = (tr[p << 1].z * tr[p << 1 | 1].z) % mod;
        tr[p].o = (tr[p << 1].o * tr[p << 1 | 1].z + tr[p << 1].z * tr[p << 1 | 1].o % mod) % mod;
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 1, 1};
        if (l == r) {
            tr[p].o = a[l];
            tr[p].z = (1 - a[l] + mod) % mod;
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
            tr[p].o = t;
            tr[p].z = (1 - t + mod) % mod;
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    node query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p];
        }

        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l > mid) return query(p << 1 | 1, l, r);
        if (mid >= r) return query(p << 1, l, r);

        node L = query(p << 1, l, r);
        node R = query(p << 1 | 1, l, r);

        node res;
        res.l = L.l;
        res.r = R.r;
        res.z = L.z * R.z % mod;
        res.o = (L.o * R.z % mod + L.z * R.o % mod) % mod;
        return res;
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <i64> v(n + 1);
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        i64 t;
        cin >> t;
        seg.a[i] = t * qpow(100, mod - 2) % mod;
    }
    seg.build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            i64 t;
            cin >> x >> t;
            t = t * qpow(100, mod - 2) % mod;
            seg.modify(1, x, t);
        }else {
            int x;
            cin >> x;
            if (x == n) {
                cout << 1 << '\n';
                continue;
            }
            auto res = seg.query(1, x + 1, n);
            cout << (res.z + res.o) % mod << '\n';
        }
    }
}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}