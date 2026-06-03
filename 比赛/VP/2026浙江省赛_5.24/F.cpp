#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    struct node {
        int l, r;
        int s, mx;
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
        tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].s = a[l];
            tr[p].mx = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, int t) {
        if (tr[p].l == tr[p].r) {
            tr[p].s = t;
            a[tr[p].l] = t;
            tr[p].mx = t;
            return;
        }
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    } 

    int query (int p, int l, int r) {
        if (l > r) return -1;
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].mx;
        }
        int res = -1;
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) res = max(res, query(p << 1, l, r));
        if (mid < r) res = max(res, query(p << 1 | 1, l, r));
        return res;
    }
};

void solve ()
{
    int n, r;
    cin >> n >> r;
    vector <int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector <int> pre(n + 1);
    set <int> st;
    st.insert(0);
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] + a[i]) % r;
        st.insert(pre[i]);
    }

    vector <int> nxt(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        if (pre[i] == 0) {
            nxt[0] = i;
            break;
        }
    }

    if (st.size() == r) {
        vector <int> v(r + 2, n + 1);
        int lft = r;
        SegTree seg(r, n + 1);
        seg.build(1, 0, r - 1);
        for (int i = n - 1; i >= 1; i--) {
            seg.modify(1, pre[i + 1], i + 1);
            if (v[pre[i + 1]] == n + 1) {
                lft--;
            }
            v[pre[i + 1]] = i + 1;
            if ((v[pre[i]] == n + 1 && lft == 1) || lft == 0) {
                int lmx = seg.query(1, 0, pre[i] - 1);
                int rmx = seg.query(1, pre[i] + 1, r - 1);
                nxt[i] = max(lmx, rmx);
            }
        }
    }

    vector <int> dp(n + 1, 1e18);
    dp[0] = 0;
    using arr2 = array <int, 2>;
    priority_queue <arr2, vector <arr2>, greater<arr2> > pq;

    pq.push({0, nxt[0]});

    for (int i = 1; i <= n; i++) {
        while (!pq.empty() && pq.top()[1] <= i) {
            pq.pop();
        }
        dp[i] = dp[i - 1] + c[i];
        
        if (!pq.empty()) {
            dp[i] = min(dp[i], pq.top()[0]);
        }
        pq.push({dp[i - 1] + c[i], nxt[i]});
    }
    cout << dp[n] << '\n';
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