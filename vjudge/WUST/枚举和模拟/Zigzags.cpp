#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m; cin >> n;
    vector <int> v(n + 1);
    vector <vector <int> > pre(n + 1, vector <int> (n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][v[i]]++;
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += pre[i - 1][v[j]] * (pre[n][v[i]] - pre[j][v[i]]);
        }
    }

    cout << ans << '\n';
    
}   
    
signed main ()
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