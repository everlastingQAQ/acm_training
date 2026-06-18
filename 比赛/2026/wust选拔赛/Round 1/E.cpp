#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU {
    vector <int> fa, rk, sz;
    int comps;

    DSU (int n = 0) {
        init(n);
    }

    void init (int n) {
        fa.resize(n + 1);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
        comps = n;
    }

    int find (int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    bool merge (int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        if (rk[x] < rk[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y]) rk[x]++;
        comps--;
        return true;
    }

    bool same (int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return true;
        else return false;
    }

    int size (int x) {
        return sz[find(x)];
    }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1), b(n + 1);
    DSU dsua(n), dsub(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i != 1) {
            if ((a[i] % 2) == (a[i - 1] % 2)) {
                dsua.merge(i, i - 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (i != 1) {
            if ((b[i] % 2) == (b[i - 1] % 2)) {
                dsub.merge(i, i - 1);
            }
        }
    }

    while (m--) {
        int ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        int faal = dsua.find(ra);
        int faar = dsua.find(rb);
        int fabl = dsub.find(ca);
        int fabr = dsub.find(cb);
        if (faal == faar && fabl == fabr) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}

int32_t main ()
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