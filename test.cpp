#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve1() {
    int n, s;
    cin >> n >> s;
    s--;
    vector<int> b(n + 5,0);
    for (int i = 1; i <= n - 1; i++) {
        b[i] = (s & 1);
        s >>= 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        int mx = max(u, v);
        int mn = min(u, v);
        if (b[u] == b[v]) cout << mx << " " << mn << endl;
        else cout << mn << " " << mx << endl;
    }
}

void solve2 ()
{
    int n;
    cin >> n;

    vector <vector <int> > e(n + 1);
    vector <set <int> > st(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        if (u > v) {
            st[u].insert(v);
        }
    }

    vector <int> a(n + 1, 0);
    auto dfs = [&] (auto self, int fa, int u, int op) -> void {
        if (!st[u].count(fa) && !st[fa].count(u)) {
            op ^= 1;
            a[u] = op;
        }else {
            a[u] = op;
        }
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v, op);
        }
    };
    dfs(dfs, 0, n, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            ans += (1LL << (i - 1));
        }
    }
    cout << ans + 1 << endl;
} 

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    int q;
    cin >> _ >> q;
    while (_--) {
        if (q == 1) solve1();
        else solve2();
    }
    return 0;
} 