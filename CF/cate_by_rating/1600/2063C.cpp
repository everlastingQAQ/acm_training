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
        iota(fa.begin(), fa.end(), 0);
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
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    int mx = -1;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }
    
    multiset <int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(ind[i]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (auto v : e[i]) {
            ans = max(ans, ind[i] + ind[v] - 2);
        }   
        st.erase(st.find(ind[i]));
        for (int v : e[i]) {
            st.erase(st.find(ind[v]));
        }
        if (!st.empty()) {
            int x = *st.rbegin();
            ans = max(ans, ind[i] + x - 1);
        }
        st.insert(ind[i]);
        for (int v : e[i]) {
            st.insert(ind[v]);
        }
    }

    cout << ans << '\n';
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