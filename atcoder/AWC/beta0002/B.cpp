#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> vis(n + 1, 1);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        if (v[t] < k) {
            vis[t] = false;
            cnt++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) ans += v[i];
    }

    cout << cnt << ' ' << ans;
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/