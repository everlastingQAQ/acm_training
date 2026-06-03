#include <bits/stdc++.h>
using namespace std;
#define int long long

struct FHQTreap {
    struct node {
        int l, r;
        int val, sz;
        int pri;
    };

    int n;
    int root = 0;
    mt19937 rng;
    vector <node> tr;

    FHQTreap(int n = 0) : rng(chrono::steady_clock::now().time_since_epoch().count()), n(n) {
        tr.reserve(n + 5);
        tr.push_back(node());
    }

    int size_of (int x) {
        return x ? tr[x].sz : 0;
    }

    void pull (int x) {
        if (!x) return;
        tr[x].sz = size_of(tr[x].l) + size_of(tr[x].r) + 1;
    }

    int nw (int val) {
        node N;
        N.l = N.r = 0;
        N.val = val;
        N.sz = 1;
        N.pri = rng();
        tr.push_back(N);
        return (int)(tr.size()) - 1;
    }

    int merge (int a, int b) {
        if (!a || !b) return a | b;
        if (tr[a].pri < tr[b].pri) {
            tr[a].r = merge(tr[a].r, b);
            pull(a);
            return a;
        }else {
            tr[b].l = merge(a, tr[b].l);
            pull(b);
            return b;
        }
    }

    void split (int p, int x, int &a, int &b) {
        if (!p) {
            a = b = 0;
            return;
        }
        if (tr[p].val <= x) {
            a = p;
            split(tr[p].r, x, tr[p].r, b);
            pull(a);
        }else {
            b = p;
            split(tr[p].l, x, a, tr[p].l);
            pull(b);
        }
    }

    void insert (int x) {
        int a, b;
        split(root, x, a, b);
        int N = nw(x);
        root = merge(merge(a, N), b);
    }

    void erase (int x) {
        int a, b, c;
        split(root, x, a, c);
        split(a, x - 1, a, b);
        if (b) b = merge(tr[b].l, tr[b].r);
        root = merge(merge(a, b), c);
    }

    int rank (int x) {
        int a, b;
        split(root, x - 1, a, b);
        int res = size_of(a) + 1;
        root = merge(a, b);
        return res;
    }

    int kth (int k) {
        int p = root;
        while (p) {
            int lsz = size_of(tr[p].l);
            if (k <= lsz) {
                p = tr[p].l;
            }else if (k == lsz + 1) {
                return tr[p].val;
            }else {
                k -= lsz + 1;
                p = tr[p].r;
            }
        }

        return -1;
    }

    int get_max (int p) {
        while (tr[p].r) p = tr[p].r;
        return tr[p].val;
    }

    int get_min (int p) {
        while (tr[p].l) p = tr[p].l;
        return tr[p].val;
    }

    int pre (int x) {
        int a, b;
        split(root, x - 1, a, b);
        int res = get_max(a);
        root = merge(a, b);
        return res;
    }

    int nxt (int x) {
        int a, b;
        split(root, x, a, b);
        int res = get_min(b);
        root = merge(a, b);
        return res;
    }
};

void solve ()
{

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