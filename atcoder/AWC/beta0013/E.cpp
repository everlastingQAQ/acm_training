#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }

    vector <int> vis(m + 1, 0);
    int ans = 0;
    auto dfs = [&] (auto self, int u, int p, int cnt) -> void {
        ans = max(ans, cnt);
        if (p == m) return;

        for (auto t : v[p]) {
            if (!vis[t]) {
                self(self, t, v[p + 1], cnt + 1);
                vis[t] = 1;
                vis[t] = 0;
                self(self, t, v[p + 1], cnt);
            }else {
                self(self, t, v[p + 1], cnt);
            }
        } 
    };
    dfs(dfs, 0, 1, 0);

    cout << ans << '\n';
}   
    
int main ()
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