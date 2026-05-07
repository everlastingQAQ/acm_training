#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector<int> fa, rk, sz;
    int comps;

    DSU(int n = 0) {
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

    int size(int x) {
        return sz[find(x)];
    }
};

void solve ()
{
	int n, x, y;
    cin >> n >> x >> y;
    vector <int> v(n + 1);
    vector <int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        if (i + x <= n) {
            dsu.merge(i, i + x);
        }
        if (i + y <= n) {
            dsu.merge(i, i + y);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dsu.find(v[i]) != dsu.find(i)) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}