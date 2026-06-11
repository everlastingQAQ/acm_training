#include <bits/stdc++.h> 
using namespace std;
#define int long long

struct SegTree {
    struct node {
        int l, r;
        int mx;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].mx = max (tr[p << 1].mx, tr[p << 1 | 1].mx);    
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};

        if (l == r) {
            tr[p].mx = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void modify (int p, int pos, int b) {
        if (tr[p].l == tr[p].r) {
            tr[p].mx = max (tr[p].mx, b);
            return;
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (pos <= mid) modify (p << 1, pos, b);
        else modify (p << 1 | 1, pos, b);

        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].mx;
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        int res = 0;
        if (l <= mid) res = max (res, query (p << 1, l, r));
        if (mid < r) res = max (res, query (p << 1 | 1, l, r));
        
        return res;
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;
    
    SegTree seg (n);
    for (int i = 1; i <= n; i ++) {
        cin >> seg.a[i];
    }

    seg.build (1, 1, n);
    while (m --) {
        char c;
        int i, b;
        cin >> c >> i >> b;
        if (c == 'Q') {
            cout << seg.query (1, i, b) << '\n';
        } else {
            seg.modify (1, i, b);
        }
    }
}


signed main () {
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_ --) ovo();
}