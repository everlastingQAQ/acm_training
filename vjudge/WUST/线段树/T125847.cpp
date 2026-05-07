#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int mod;
const int MAXN = 8e6;

struct DynamicSegTree {
    struct node {
        int ls, rs;
        int s, lz;
        bool tag;
    };

    node tr[MAXN];
    int tot;

    DynamicSegTree () {
        tot = 1;
    }

    int newnode () {
        tr[++tot] = {0, 0, 0, 0, false};
        return tot;
    }

    void push_up (int p) {
        tr[p].s = 0;
        if (tr[p].ls) tr[p].s = (tr[p].s + tr[tr[p].ls].s) % mod;
        if (tr[p].rs) tr[p].s = (tr[p].s + tr[tr[p].rs].s) % mod;
    }

    void apply (int p, int l, int r, i64 v) {
        tr[p].s += (r - l + 1) % mod * v % mod;
        tr[p].lz += v;
        tr[p].tag = true;
    }

    void push_down (int p, int l, int r) {
        if (!tr[p].tag) return;
        int mid = (l + r) >> 1;
        if (!tr[p].ls) tr[p].ls = newnode();
        if (!tr[p].rs) tr[p].rs = newnode();
        apply(tr[p].ls, l, mid, tr[p].lz);
        apply(tr[p].rs, mid + 1, r, tr[p].lz);
        tr[p].tag = false;
        tr[p].lz = 0;
    }

    void modify (int p, int l, int r, int ql, int qr, i64 v) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, v);
            return;
        }
        push_down(p, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            if (!tr[p].ls) tr[p].ls = newnode();
            modify(tr[p].ls, l, mid, ql, qr, v);
        }
        if (mid < qr) {
            if (!tr[p].rs) tr[p].rs = newnode();
            modify(tr[p].rs, mid + 1, r, ql, qr, v);
        }
        push_up(p);
    }

    i64 query (int p, int l, int r, int ql, int qr) {
        if (!p) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return tr[p].s;
        }
        push_down(p, l, r);
        int mid = (l + r) >> 1;
        i64 res = 0;
        if (ql <= mid) res = (res + query(tr[p].ls, l, mid, ql, qr)) % mod;
        if (mid < qr) res = (res + query(tr[p].rs, mid + 1, r, ql, qr)) % mod;
        return res;
    }
};

void solve ()
{
    int q;
    cin >> q >> mod;
    int R = 1000000000;
    DynamicSegTree seg;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.modify(1, 1, R, l, r, v);
        }else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, R, l, r) << '\n';
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