#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    using arr2 = array <int, 2>;
    vector <arr2> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    DSU dsu(n);
    auto check = [&] (int x) -> bool {
        dsu.init(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]) <= x * 2) {
                    dsu.merge(i, j);
                }
            }
        }
        return (dsu.comps == 1);
    };

    int l = 1, r = 1e10;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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