#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

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
    int n;
    cin >> n;
    DSU dsu(n);
    vector <int> v(n + 1), ind(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dsu.merge(i, v[i]);
        ind[v[i]]++;
    }

    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }
 
    vector <int> vis(n + 1, 1);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        vis[x] = false;
        int t = v[x];
        if (--ind[t] == 0) q.push(t);
    }

    vector <int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        int t = dsu.find(i);
        if (vis[i]) c[t]++;
    }

    i64 ans = 1;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) != i) continue;
        ans = ans * qpow(25, dsu.size(i) - c[i]) % mod;
        ans = ans * ((qpow(25, c[i]) + 25 * qpow(-1, c[i]) + mod) % mod) % mod;
    }

    cout << ans << '\n';
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
