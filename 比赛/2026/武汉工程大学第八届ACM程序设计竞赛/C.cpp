#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector<int> fa, rk, sz;
    int comps;
    int n;

    DSU(int n = 0) : n(n) {
        init(n);
    }

    void init(int n) {
        fa.resize(n + 1);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        ranges::iota(fa, 0);
        comps = n;
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    bool merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        if (rk[x] < rk[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y]) rk[x]++;
        comps--;
        return true;
    }

    void erase (int x) {
        fa[x] = find(x + 1);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int res = 0;
        int x = dsu.find(l);
        while (x <= r) {
            dsu.erase(x);
            x = dsu.find(x);
            res++;
        }
        cout << res << '\n';
    }
}

int main ()
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