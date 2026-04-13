#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
const int M = 1e5 + 5;

int a[M];
struct ty {
    int l, r;
    ll sum, f;
}tr[4 * M];
#define ls(x) (tr[x].l)
#define rs(x) (tr[x].r)
#define f(x) (tr[x].f)
#define sum(x) (tr[x].sum)
void pushup(int x) {
    sum(x) = sum(ls(x)) + sum(rs(x));
}
void pushdown(int x, int l, int r) {
    if (!f(x)) return ;
    int v = f(x);
    f(x) = 0;
    int mid = l + (r - l) / 2; 
    sum(ls(x)) += v * (mid - l + 1);
    sum(rs(x)) += v * (r - mid);
    f(ls(x)) += v;
    f(rs(x)) += v;
}
void build(int x, int l, int r) {
    if (l == r) {
        sum(x) = a[l];
        return ;
    }
    ls(x) = x << 1;
    rs(x) = x << 1 | 1;
    int mid = l + (r - l) / 2;
    build(ls(x), l, mid);
    build(rs(x), mid + 1, r);
    pushup(x);
}
void add(int x, int l, int r, int al, int ar, ll val) {
    if (al <= l && ar >= r) {
        f(x) += val;
        sum(x) += val * (r - l + 1);
        return ;
    }
    pushdown(x, l, r);
    int mid = l + (r - l) / 2;
    if (al <= mid) add(ls(x), l, mid, al, ar, val);
    if (ar > mid) add(rs(x), mid + 1, r, al, ar, val);
    pushup(x);
} 
ll ask(int x, int l, int r, int al ,int ar) {
    if (al <= l && ar >= r) {
        return sum(x);
    }
    ll res = 0;
    pushdown(x, l, r);
    int mid = l + (r - l) / 2;
    if (al <= mid) res += ask(ls(x), l, mid, al, ar);
    if (ar > mid) res += ask(rs(x), mid + 1, r, al, ar);
    return res;
}

void solve ()
{
    int n, q;
    cin >> n >> q;
    SegTree seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            i64 k;
            cin >> p >> k;
            seg.modify(1, p, k);
        }else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, l, r) << '\n';
        }
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 