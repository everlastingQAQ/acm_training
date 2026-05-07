#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
const int MX = 1e9 + 2e8;

struct DynamicSegTree {
    struct node {
        int ls, rs;
        i64 s, lz;
        bool tag;
    };

    vector <node> tr;

    DynamicSegTree () {
        tr.reserve(8e6);
        tr.push_back({0, 0, 0, 0, false});
        tr.push_back({0, 0, 0, 0, false});
    }

    int nw () {
        tr.push_back({0, 0, 0, 0, false});
        return tr.size() - 1;
    }

    void push_up (int p) {
        tr[p].s = 0;
        if (tr[p].ls) tr[p].s = (tr[p].s + tr[tr[p].ls].s) % mod;
        if (tr[p].rs) tr[p].s = (tr[p].s + tr[tr[p].rs].s) % mod;
    }

    void apply (int p, int l, int r, i64 t) {
        tr[p].s = (tr[p].s + (r - l + 1) % mod * t % mod) % mod;
        tr[p].lz = (tr[p].lz + t) % mod;
        tr[p].tag = 1;
    }

    void push_down (int p, int l, int r) {
        if (!tr[p].tag || l == r) return;
        int mid = l + ((r - l) >> 1);
        if (!tr[p].ls) tr[p].ls = nw();
        if (!tr[p].rs) tr[p].rs = nw();
        apply(tr[p].ls, l, mid, tr[p].lz);
        apply(tr[p].rs, mid + 1, r, tr[p].lz);
        tr[p].tag = 0;
        tr[p].lz = 0;
    }

    void modify (int p, int l, int r, int ql, int qr, i64 t) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, t);
            return;
        }
        push_down(p, l, r);
        int mid = l + ((r - l) >> 1);
        if (ql <= mid) {
            if (!tr[p].ls) tr[p].ls = nw();
            modify(tr[p].ls, l, mid, ql, qr, t);
        }
        if (mid < qr) {
            if (!tr[p].rs) tr[p].rs = nw();
            modify(tr[p].rs, mid + 1, r, ql, qr, t);
        }
        push_up(p);
    }

    i64 query (int p, int l, int r, int ql, int qr) {
        if (!p || ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) {
            return tr[p].s;
        }
        push_down(p, l, r);
        i64 res = 0;
        int mid = l + ((r - l) >> 1);
        if (ql <= mid) res = (res + query(tr[p].ls, l, mid, ql, qr)) % mod;
        if (mid < qr) res = (res + query(tr[p].rs, mid + 1, r, ql, qr)) % mod;
        return res;
    }
};

void solve ()
{
    int q;
    cin >> q;
    i64 pre = 0;
    DynamicSegTree seg;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            i64 t;
            cin >> l >> r >> t;
            l = (l ^ pre) % MX + 1;
            r = (r ^ pre) % MX + 1;
            if (l > r) swap(l, r);
            seg.modify(1, 1, MX, l, r, t);
        }else {
            int l, r;
            cin >> l >> r;
            l = (l ^ pre) % MX + 1;
            r = (r ^ pre) % MX + 1;
            if (l > r) swap(l, r);
            pre = seg.query(1, 1, MX, l, r);
            cout << pre << '\n';
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