#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ind[v]++;
        e[u].push_back(v);
    }

    queue <int> q;
    vector <int> vis(n + 1, 0);
    vector <int> ans;
    vector <int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i] != 0) continue;
        vis[i] = 1;
        auto dfs = [&] (auto self, int u) -> void {
            for (auto v : e[u]) {
                if (vis[v] == 1) {
                    pre[i] = v;
                    int cur = v;
                    vector <int> ans;
                    pre[v] = u;
                    for (int j = 1; j <= n; j++) {
                        cur = pre[cur];
                    }
                    int x = cur;
                    do {
                        ans.push_back(cur);
                        cur = pre[cur];
                    }while(cur != x);
                    ans.push_back(x);
                    reverse(ans.begin(), ans.end());
                    cout << ans.size() << '\n';
                    for (auto x : ans) {
                        cout << x << ' ';
                    }
                    exit(0);
                }else if (vis[v] == 0) {
                    pre[v] = u;
                    vis[v] = 1;
                    self(self, v);
                }
            }
            vis[u] = 2;
        };
        dfs(dfs, i);
        vis[i] = 2;
    }

    cout << "IMPOSSIBLE\n";
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