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

    void build (int p, int l, int r, int x) {
        tr[p] = {l, r, 0};
        if (l == r) {
            tr[p].s = a[l] = x;
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(p << 1, l, mid, x);
        build(p << 1 | 1, mid + 1, r, x);
        push_up(p);
    }

    void modify (int p, int x, int t) {
        if (tr[p].l == tr[p].r) {
            a[tr[p].l] = t;
            tr[p].s = t;
            return;
        }
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    } 

    int query (int p, int x) {
        if (tr[p].l == tr[p].r) {
            return tr[p].l;
        }
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (tr[p << 1].s >= x) return query(p << 1, x);
        else return query(p << 1 | 1, x - tr[p << 1].s);
    }

};

void solve ()
{
    int q, c;
    cin >> q >> c;
    using arr3 = array <int, 3>;
    vector <arr3> v(q + 1);
    int cx = 0, cy = 0;
    for (int i = 1; i <= q; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        if (v[i][0] == 1) cx++;
        if (v[i][0] == 2) cy++;
    }
    
    int n = cx + 1, m = cy + 1;

    SegTree segx(n);
    segx.build(1, 1, n, 1);
    using arr2 = array <int, 2>;
    vector <arr2> x(n + 1);
    vector <int> px(q + 1);
    for (int i = q; i >= 1; i--) {
        if (v[i][0] == 1) {
            int pos = segx.query(1, v[i][1] + 1);
            px[i] = pos;
            x[pos] = {i, v[i][2]};
            segx.modify(1, pos, 0);
        }
    }
    int pcx = segx.query(1, 1);
    x[pcx] = {0, c};

    SegTree segy(m);
    segy.build(1, 1, m, 1);
    vector <arr2> y(m + 1);
    vector <int> py(q + 1);
    for (int i = q; i >= 1; i--) {
        if (v[i][0] == 2) {
            int pos = segy.query(1, v[i][1] + 1);
            py[i] = pos;
            y[pos] = {i, v[i][2]};
            segy.modify(1, pos, 0);
        }
    }
    int pcy = segy.query(1, 1);
    y[pcy] = {0, c};

    SegTree sx(n), sy(m);
    sx.build(1, 1, n, 0);
    sy.build(1, 1, m, 0);
    sx.modify(1, pcx, 1);
    sy.modify(1, pcy, 1);
    for (int i = 1; i <= q; i++) {
        if (v[i][0] == 1) {
            sx.modify(1, px[i], 1);
        }else if (v[i][0] == 2) {
            sy.modify(1, py[i], 1);
        }else {
            int posx = sx.query(1, v[i][1]);
            int posy = sy.query(1, v[i][2]);
            if (x[posx][0] > y[posy][0]) {
                cout << x[posx][1] << '\n';
            }else {
                cout << y[posy][1] << '\n';
            }
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