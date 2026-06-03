#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin() + 1, v[i].end());
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        int cur = 1e18;
        for (int i = 1; i <= n; i++) {
            cur = min(cur, v[i][j]);
        }
        ans += cur;
    }

    cout << ans << '\n';
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