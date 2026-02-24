#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
    public: 
        vector <int> fa, rk, sz;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
            ranges::iota(fa, 0LL);
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
            return true;
        }

        int size (int x) {
            return sz[find(x)];
        }
};

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 3> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        int ans = n;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (v[i][0] == v[j][0]) {
                ans--;
                continue;
            }
            int a1 = (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]);
            int b1 = 4 * (v[i][0] - v[j][0]) * (v[i][2] - v[j][2]);
            if (a1 >= b1) {
                dsu.merge(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            cout << n - 1 << ' ';
        }else {
            cout << n - dsu.size(i) + 1 << ' ';
        }
    }
    cout << '\n';
}   
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/