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

    SegTree (int n = 0, int x = 0) : n(n) {
        a.assign(n + 1, x);
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
            tr[p].s = a[tr[p].l] = t;
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
        if (tr[p << 1].s >= x) return query(p << 1, x);
        else return query(p << 1 | 1, x - tr[p << 1].s);
    }
};

void solve ()
{
    int q, c;
    cin >> q >> c;
    using arr3 = array <int, 3>;
    using arr2 = array <int, 2>;
    vector <arr3> v(q + 1);
    int cx = 0, cy = 0;
    for (int i = 1; i <= q; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        if (v[i][0] == 1) cx++;
        if (v[i][0] == 2) cy++;
    }

    int n = cx + 1, m = cy + 1;
    SegTree segx(n, 1), segy(m, 1);
    segx.build(1, 1, n), segy.build(1, 1, m);
    vector <arr2> x(n + 1), y(m + 1);
    vector <int> px(q + 1), py(q + 1);

    for (int i = q; i >= 1; i--) {
        if (v[i][0] == 2 || v[i][0] == 3) continue;
        int pos = segx.query(1, v[i][1] + 1);
        x[pos][0] = i, x[pos][1] = v[i][2];
        px[i] = pos;
        segx.modify(1, pos, 0);
    }
    int pix = segx.query(1, 1);
    x[pix][0] = 0, x[pix][1] = c;
    px[0] = pix;

    for (int i = q; i >= 1; i--) {
        if (v[i][0] == 1 || v[i][0] == 3) continue;
        int pos = segy.query(1, v[i][1] + 1);
        y[pos][0] = i, y[pos][1] = v[i][2];
        py[i] = pos;
        segy.modify(1, pos, 0);
    }
    int piy = segy.query(1, 1);
    y[piy][0] = 0, y[piy][1] = c;
    py[0] = piy;

    SegTree xx(n, 0), yy(m, 0);
    xx.build(1, 1, n), yy.build(1, 1, m);
    xx.modify(1, px[0], 1), yy.modify(1, py[0], 1);

    for (int i = 1; i <= q; i++) {
        if (v[i][0] == 1) {
            xx.modify(1, px[i], 1);
        }else if (v[i][0] == 2) {
            yy.modify(1, py[i], 1);
        }else {
            int pxx = xx.query(1, v[i][1]);
            int pyy = yy.query(1, v[i][2]);
            if (x[pxx][0] > y[pyy][0]) {
                cout << x[pxx][1] << '\n';
            }else {
                cout << y[pyy][1] << '\n';
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