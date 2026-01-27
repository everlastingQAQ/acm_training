#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1), a(n + 1), d(n + 1);
    map <int, int> mp;
    for (int i = 1; i <= n; i++) cin >> v[i], mp[v[i]] = i;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> d[i];

    vector <int> vis(n + 1, 0);
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[v[a[i]]]) {
            cout << sum << ' ';
            continue;
        }
        int cnt = 1;
        int t = v[a[i]];
        auto dfs = [&] (int u, auto self) -> void {
            if (u == t) {
                vis[t] = true;
                sum += cnt;
                return;
            }
            cnt++;
            self(d[mp[u]], self);
            vis[u] = true;
        };
        dfs(d[a[i]], dfs);
        cout << sum << ' ';
    }
    
}   
    
signed main ()
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