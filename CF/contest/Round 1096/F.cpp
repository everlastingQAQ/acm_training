#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    struct node {
        int l, r;
        int s, lz;
    };

    vector <int> a;
    vector <node> tr;
    int n;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
    }

    void apply (int p, int x) {
        tr[p].lz += x;
        tr[p].s += (tr[p].r - tr[p].l + 1) * x;
    }

    void push_down (int p) {
        if (tr[p].lz) {
            apply(p << 1, tr[p].lz);
            apply(p << 1 | 1, tr[p].lz);
            tr[p].lz = 0;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].s = a[l] = 0;
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

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }
        push_down(p);
        int res = 0;
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) res += query(p << 1, l, r);
        if (mid < r) res += query(p << 1 | 1, l, r); 
        return res;
    }

};

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    SegTree seg(n);
    seg.build(1, 1, n);
    int mn = v[n];
    seg.modify(1, 1, v[n], 1);
    for (int i = n - 1; i >= 1; i--) {
        if (v[i] > mn) {
            int cur = (v[i] - mn) * (n - i) - seg.query(1, mn + 1, v[i]);
            ans += cur;
        }else {
            mn = v[i];
        }
        seg.modify(1, 1, v[i], 1);
    }

    vector <int> cnt(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[v[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    int anss = 0;
    for (int i = 1; i <= n; i++) {
        anss = max(anss, i - 1 - pre[v[i] - 1]);
    }

    cout << ans + anss << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}