#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <int> > dis(n + 1, vector <int> (n + 1));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        dis[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 1;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = dis[i][j] | (dis[i][k] & dis[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!dis[i][j] && !dis[j][i]) cnt++;
        }
        if (cnt == 0) ans++;
    }
    cout << ans << '\n';
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