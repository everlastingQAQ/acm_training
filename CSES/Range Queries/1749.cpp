#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve1 ()
{
    int n;
    cin >> n;
    ordered_set <array <int, 2> > st;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        st.insert({i, t});
    }
    for (int i = 1; i <= n; i++) {
        int pos;
        cin >> pos;
        auto it = st.find_by_order(pos - 1);
        cout << (*it)[1] << ' ';
        st.erase(it);
    }
}   
    
struct SegTree {
    struct node {
        int l, r;
        int s;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 1);
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

void solve2 ()
{
    int n;
    cin >> n;
    SegTree seg(n);
    seg.build(1, 1, n);
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        int pos;
        cin >> pos;
        int p = seg.query(1, pos);
        cout << v[p] << ' ';
        seg.modify(1, p, 0);
    }
}

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve2();
    }
    return 0;
} 