#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;

using arr3 = array <int, 3>;
using arr2 = array <int, 2>;
arr3 v[N];
arr2 a[N];
int res[N];

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
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= m; i++) {
        cin >> v[i][1] >> v[i][2] >> v[i][0];
    }
    sort(v + 1, v + m + 1);

    for (int i = 1; i <= q; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a + 1, a + q + 1);

    DSU dsu(n);
    int idx = 1;

    auto cal = [] (int x) -> int {
        int c = x * (x - 1) / 2;
        return c;
    };

    int ans = 0;
    for (int i = 1; i <= q; i++) {
        while (idx <= m && v[idx][0] <= a[i][0]) {
            int fa1 = dsu.find(v[idx][1]);
            int fa2 = dsu.find(v[idx][2]);
            if (fa1 == fa2) {
                idx++;
                continue;
            }
            ans -= cal(dsu.sz[fa1]);
            ans -= cal(dsu.sz[fa2]);
            dsu.merge(fa1, fa2);
            int fa = dsu.find(v[idx][1]);
            ans += cal(dsu.sz[fa]);
            idx++;
        }
        res[a[i][1]] = ans;
    }

    for (int i = 1; i <= q; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
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