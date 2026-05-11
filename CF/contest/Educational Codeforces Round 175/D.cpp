#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        e[u].push_back(i);
        e[i].push_back(u);
    }

    vector <int> dis(n + 1, 0);
    dis[0] = -1;
    
    auto dfs1 = [&] (auto self, int fa, int u) -> void {
        dis[u] = dis[fa] + 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
        }
    };
    dfs1(dfs1, 0, 1);

    vector <int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[dis[i]]++;
        // cout << dis[i] << ' ' << i << '\n';
    }

    vector <i64> dp(n + 1);
    dp[1] = a[1];
    vector <i64> b(n + 1, 0);

    queue <array <int, 2> > q;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 1) {
            b[i] = 1;
            q.push({i, 1});
        }
    }

    while (q.size()) {
        auto [u, fa] = q.front();
        q.pop();

        if (dis[u] >= 2) {
            dp[dis[u]] = (dp[dis[u]] + (dp[dis[u] - 1] - b[fa] + mod) % mod) % mod;
            b[u] = (dp[dis[u] - 1] - b[fa]) % mod;
        }
        
        for (auto v : e[u]) {
            if (v == fa) {
                continue;
            }
            q.push({v, u});
        }
    }

    i64 ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i] % mod) % mod;
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