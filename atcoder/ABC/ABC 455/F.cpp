#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

struct SegTree {
    struct node {
        int l, r;
        int s, w;
        int lzs;
        bool tag;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        tr[p].s = (tr[p << 1].s + tr[p << 1 | 1].s) % mod;
        tr[p].w = ((tr[p << 1].w + tr[p << 1 | 1].w) % mod + tr[p << 1].s * tr[p << 1 | 1].s % mod) % mod;
    }

    void apply (int p, int x) {
        int len = tr[p].r - tr[p].l + 1;
        int xx1 = len * (len - 1) / 2;
        int x1 = x * x % mod * xx1 % mod;
        int x2 = (len - 1) * x % mod * tr[p].s % mod;
        tr[p].w = ((tr[p].w + x2) % mod + x1) % mod;
        tr[p].s = (tr[p].s + len * x % mod) % mod;
        tr[p].tag = true;
        tr[p].lzs = (tr[p].lzs + x) % mod;
    }

    void push_down (int p) {
        if (tr[p].tag) {
            apply(p << 1, tr[p].lzs);
            apply(p << 1 | 1, tr[p].lzs);
            tr[p].tag = false;
            tr[p].lzs = 0;
        }
    } 

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, 0, 0};
        if (l == r) {
            tr[p].s = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int l, int r, int t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply(p, t);
            return;
        }
        push_down(p);
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) modify(p << 1, l, r, t);
        if (mid < r) modify(p << 1 | 1, l, r, t);
        push_up(p);
    }

    node query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) return tr[p];
        push_down(p);
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (r <= mid) return query(p << 1, l, r);
        if (l > mid) return query(p << 1 | 1, l, r);
        node L = query(p << 1, l, r);
        node R = query(p << 1 | 1, l, r);
        node res;

        res.l = L.l;
        res.r = R.r;
        res.s = (L.s + R.s) % mod;

        res.w = ((L.s * R.s % mod + L.w) % mod + R.w) % mod;
        return res; 
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    SegTree seg(n);
    seg.build(1, 1, n);
    while (q--) {
        int l, r, t;
        cin >> l >> r >> t;
        seg.modify(1, l, r, t);
        cout << seg.query(1, l, r).w << '\n';
    }
}   
    
int32_t main ()
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