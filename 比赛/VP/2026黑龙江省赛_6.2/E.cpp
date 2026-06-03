#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e11;

struct SegTree {
    struct node {
        int l, r;
        int s, dis, mn;
        int lz;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        tr[p].dis = tr[p << 1].dis + tr[p << 1 | 1].dis;
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
        tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
    }

    void apply (int p, int t) {
        tr[p].dis += t * (tr[p].r - tr[p].l + 1);
        tr[p].s += t * (tr[p].r - tr[p].l + 1);
        tr[p].lz += t;
        tr[p].mn += t;
    }

    void push_down (int p) {
        if (tr[p].lz != 0) {
            apply(p << 1, tr[p].lz);
            apply(p << 1 | 1, tr[p].lz);
            tr[p].lz = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0, INF, 0};
        if (l == r) {
            tr[p].s = INF;
            tr[p].dis = a[l];
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

    void modify1 (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            if (tr[p].s >= 1e10) {
                tr[p].s = tr[p].dis;
                tr[p].mn = tr[p].dis;
            }else {
                tr[p].s = INF;
                tr[p].mn = INF;
            }
            return;
        }
        push_down(p);
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) modify1(p << 1, l, r);
        if (mid < r) modify1(p << 1 | 1, l, r);
        push_up(p);
    }

    int query () {
        return tr[1].mn;
    }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> val;
    val.reserve(2 * n);
    vector <int> dist(n + 1, 0);
    dist[1] = 0;

    auto dfs = [&] (auto self, int fa, int u) -> void {
        val.push_back(u);
        for (auto v : e[u]) {
            if (v == fa) continue;
            dist[v] = dist[u] + 1;
            self(self, u, v);
        }
        val.push_back(u);
    };
    dfs(dfs, 0, 1);

    vector <array <int, 2> > pos(n + 1, {-1, -1});
    for (int i = 0; i <= 2 * n - 1; i++) {
        if (pos[val[i]][0] == -1) {
            pos[val[i]][0] = i + 1;
        }else {
            pos[val[i]][1] = i + 1;
        }
    }

    SegTree seg(2 * n);
    for (int i = 0; i <= 2 * n - 1; i++) {
        seg.a[i + 1] = dist[val[i]];
    }
    seg.build(1, 1, 2 * n);

    int cur = 1;
    for (int i = 1; i <= m; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            cin >> x;
            seg.modify1(1, pos[x][0], pos[x][0]);
            seg.modify1(1, pos[x][1], pos[x][1]);
        }else {
            int x;
            cin >> x;
            int p0x = pos[x][0];
            int p1x = pos[x][1];
            int p0c = pos[cur][0];
            int p1c = pos[cur][1];

            if (dist[cur] < dist[x]) {
                seg.modify(1, p0x, p1x, -1);
                seg.modify(1, 1, p0x - 1, 1);
                seg.modify(1, p1x + 1, 2 * n, 1);
            }else {
                seg.modify(1, p0c, p1c, 1);
                seg.modify(1, 1, p0c - 1, -1);
                seg.modify(1, p1c + 1, 2 * n, -1);
            } 
            cur = x;

        }
        int ans = seg.query();
        if (ans >= 1e10) {
            cout << 2147483648 << '\n';
        }else {
            cout << ans << '\n';
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