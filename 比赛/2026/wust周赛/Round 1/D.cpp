#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    s = ' ' + s;
    
    vector <int> vis(n + 1, 0);
    vector <int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        int cnt = 0;
        auto dfs = [&] (auto self, int u) -> void {
            if (vis[u]) {
                return;
            }
            // cout << i << ' ' << u << '\n';
            vis[u] = true;
            if (s[u] == '0') cnt++;
            self(self, v[u]);
            ans[u] = cnt;
        };

        dfs(dfs, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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