#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    vector <int> out(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        ind[v]++;
        out[u]++;
    }
    
    queue <int> q;
    vector <int> dp(n + 1, 0);
    vector <int> fi;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }else if (out[i] == 0) {
            fi.push_back(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            dp[v] += dp[u];
            if (--ind[v] == 0) q.push(v);
        }
    }

    int ans = 0;
    for (auto x : fi) {
        ans += dp[x];
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