#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int mod;

struct DynamicSegTree {
    struct node {
        int ls, rs;
        i64 s, lz1, lz2;
        bool tg;
    };

    vector <node> tr;

    DynamicSegTree () {
        tr.reserve(8e6);
        tr.push_back({0, 0, 0, 1, 0, 0});
        tr.push_back({0, 0, 0, 1, 0, 0});
    }

    int nw () {
        tr.push_back({0, 0, 0, 1, 0, 0});
        return tr.size() - 1;
    }

    void push_up (int p) {
        tr[p].s = 0;
        if (tr[p].ls) tr[p].s = (tr[p].s + tr[tr[p].ls].s) % mod;
        if (tr[p].rs) tr[p].s = (tr[p].s + tr[tr[p].rs].s) % mod;
    }

    void apply (int p, int l, int r, i64 x, i64 y) {
        tr[p].s = (tr[p].s * x % mod + (r - l + 1) * y % mod) % mod;
        tr[p].lz1 = (tr[p].lz1 * x) % mod;
        tr[p].lz2 = (tr[p].lz2 * x % mod + y) % mod;
        tr[p].tg = true;
    }

    void push_down (int p, int l, int r) {
        if (!tr[p].tg || l == r) return;
        int mid = l + ((r - l) >> 1);
        if (!tr[p].ls) tr[p].ls = nw();
        if (!tr[p].rs) tr[p].rs = nw();
        apply(tr[p].ls, l, mid, tr[p].lz1, tr[p].lz2);
        apply(tr[p].rs, mid + 1, r, tr[p].lz1, tr[p].lz2);
        tr[p].lz1 = 1;
        tr[p].lz2 = 0;
        tr[p].tg = false;
    }
    
    void modify (int p, int l, int r, int ql, int qr, i64 x, i64 y) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, x, y);
            return;
        }
        push_down(p, l, r);
        int mid = l + ((r - l) >> 1);
        if (ql <= mid) {
            if (!tr[p].ls) tr[p].ls = nw();
            modify(tr[p].ls, l, mid, ql, qr, x, y);
        }
        if (mid < qr) {
            if (!tr[p].rs) tr[p].rs = nw();
            modify(tr[p].rs, mid + 1, r, ql, qr, x, y);
        }
        push_up(p);
    }

    i64 query (int p, int l, int r, int ql, int qr) {
        if (!p || l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return tr[p].s;
        }
        push_down(p, l, r);
        i64 res = 0;
        int mid = l + ((r - l) >> 1);
        res = (res + query(tr[p].ls, l, mid, ql, qr)) % mod;
        res = (res + query(tr[p].rs, mid + 1, r, ql, qr)) % mod;
        return res;
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q >> mod;
    DynamicSegTree seg;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            k %= mod;
            seg.modify(1, 1, n, l, r, k, 0);
        }else if (op == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            k %= mod;
            seg.modify(1, 1, n, l, r, 1, k);
        }else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, n, l, r) << '\n';
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