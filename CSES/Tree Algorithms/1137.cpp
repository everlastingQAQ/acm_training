#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    struct node {
        int l, r;
        int s;
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
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) {
            tr[p].s = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, int t) {
        if (tr[p].l == tr[p].r) {
            a[tr[p].l] = tr[p].s = t;
            return;
        }
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        int res = 0;
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) res += query(p << 1, l, r);
        if (mid < r) res += query(p << 1 | 1, l, r);
        return res;
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <int> order;
    order.reserve(2 * n + 1);
    order.push_back(0);

    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs = [&] (auto self, int fa, int u) -> void {
        order.push_back(u);
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
        }
        order.push_back(u);
    };
    dfs(dfs, 0, 1);

    int m = order.size();
    SegTree seg(m - 1);
    vector <array <int, 2> > pos(n + 1, {-1, -1});
    for (int i = 1; i < m; i++) {
        seg.a[i] = val[order[i]];
        if (pos[order[i]][0] == -1) {
            pos[order[i]][0] = i;
        }else {
            pos[order[i]][1] = i;
        }
    }
    seg.build(1, 1, m - 1);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int s, x;
            cin >> s >> x;
            seg.modify(1, pos[s][0], x);
            seg.modify(1, pos[s][1], x); 
        }else {
            int s;
            cin >> s;
            int res = seg.query(1, pos[s][0], pos[s][1]) / 2;
            cout << res << '\n';
        }
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