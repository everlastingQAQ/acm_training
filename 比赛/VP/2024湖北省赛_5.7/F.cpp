#include <bits/stdc++.h>
using namespace std;
#define int long long

const int lim = 19260817;
const int mod = 1e9 + 7;

int qpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct PSegTree {
    struct node {
        int ls, rs;
        int s;
    };

    int n;
    vector <int> a;
    vector <node> tr;
    vector <int> rt;

    PSegTree (int n = 0, int m = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.reserve(2 * n + (m + 5) * 25);
        tr.push_back({0, 0, 0});
        rt.assign(m + 1, 0);
    }

    int nw () {
        tr.push_back({0, 0, 0});
        return tr.size() - 1;
    }

    int clone (int p) {
        tr.push_back(tr[p]);
        return tr.size() - 1;
    }

    void push_up (int p) {
        tr[p].s = tr[tr[p].ls].s + tr[tr[p].rs].s;
    }

    int build (int l, int r) {
        int p = nw();
        if (l == r) {
            tr[p].s = a[l];
            return p;
        }
        int mid = l + ((r - l) >> 1);
        tr[p].ls = build(l, mid);
        tr[p].rs = build(mid + 1, r);
        push_up(p);
        return p;
    }
    
    int modify (int p, int l, int r, int x, int t) {
        int q = clone(p);
        if (l == r) {
            tr[q].s = t;
            return q;
        }
        int mid = l + ((r - l) >> 1);
        if (x <= mid) {
            tr[q].ls = modify(tr[p].ls, l, mid, x, t);
        }else {
            tr[q].rs = modify(tr[p].rs, mid + 1, r, x, t);
        }
        push_up(q);
        return q;
    }

    int query (int p, int l, int r, int ql, int qr) {
        if (!p || l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return tr[p].s;
        int mid = l + ((r - l) >> 1);
        int res = 0;
        if (ql <= mid) {
            res += query(tr[p].ls, l, mid, ql, qr);
        }
        if (mid < qr) {
            res += query(tr[p].rs, mid + 1, r, ql, qr);
        }
        return res;
    }

};

void solve ()
{
    int n, m, A, p, q;
    cin >> n >> m >> A >> p >> q;
    auto rnd = [&] () -> int {
        A = (7 * A + 13) % lim;
        return A;
    };

    PSegTree seg(n, m);

    for (int i = 1; i <= n; i++) {
        int t = rnd() % q + 1;
        seg.a[i] = 1LL << t;
    }

    seg.rt[0] = seg.build(1, n);

    for (int i = 1; i <= m; i++) {
        int op = rnd() % p + 1;
        if (op == 1) {
            int L = rnd() % n + 1;
            int R = rnd() % n + 1;
            int l = min(L, R), r = max(L, R);
            int sum = seg.query(seg.rt[i - 1], 1, n, l, r);
            int ans = (63 - __builtin_clzll(sum)) % mod;
            cout << ans << '\n';
            seg.rt[i] = seg.rt[i - 1];
        }else if (op == 2) {
            int L = rnd() % n + 1;
            int R = rnd() % n + 1;
            int k = rnd() % q + 1;
            int l = min(L, R), r = max(L, R);
            int sum = seg.query(seg.rt[i - 1], 1, n, l, r);
            int t = k;
            while (sum & (1LL << t)) t++;
            int ans = (qpow(2, t + 1) - qpow(2, k + 1) + mod) % mod;
            cout << ans << '\n';
            seg.rt[i] = seg.rt[i - 1];
        }else if (op == 3) {
            int pos = rnd() % n + 1;
            int k = rnd() % q + 1;
            seg.rt[i] = seg.modify(seg.rt[i - 1], 1, n, pos, 1LL << k);
        }else if (op == 4) {
            int t = rnd() % i;
            seg.rt[i] = seg.rt[t];
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