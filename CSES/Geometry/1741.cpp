#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    struct node {
        int l, r;
        int s, len;
    };
    
    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        if (tr[p].s > 0) {
            tr[p].len = a[tr[p].r + 1] - a[tr[p].l];
        }else {
            if (tr[p].l == tr[p].r) tr[p].len = 0;
            else tr[p].len = tr[p << 1].len + tr[p << 1 | 1].len;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
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
            tr[p].s += t;
            push_up(p);
            return;
        }
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) modify(p << 1, l, r, t);
        if (mid < r) modify(p << 1 | 1, l, r, t);
        push_up(p);
    }

    int query () {
        return tr[1].len;
    }

};

void solve ()
{
    int n;
    cin >> n;
    vector <int> y;
    y.reserve(2 * n);
    vector <array <int, 4> > v;
    v.reserve(2 * n);
    
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1, y1, y2, 1});
        v.push_back({x2, y1, y2, -1});
        y.push_back(y1);
        y.push_back(y2);
    }

    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    sort(v.begin(), v.end(), [] (auto &a, auto &b) {
        return a[0] < b[0];
    });

    int m = y.size();
    
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