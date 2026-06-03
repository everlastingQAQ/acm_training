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
        tr[p].s = (tr[p << 1].s + tr[p << 1 | 1].s);
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
            tr[p].s += t;
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
    int n;
    cin >> n;
    int m = 2 * n;
    vector <int> v(m + 1);
    map <int, int> mp;
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
        if (mp[v[i]]) {
            mp[v[i]] = i;
        }else {
            mp[v[i]] = true;
        }
    }

    SegTree seg(m);
    seg.build(1, 1, m);
    map <int, int> mp1;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (mp1[v[i]]) continue;
        ans += seg.query(1, i, mp[v[i]]);
        seg.modify(1, mp[v[i]], 1);
        mp1[v[i]] = true;
    }
    cout << ans << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}