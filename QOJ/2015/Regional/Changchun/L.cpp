#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 10, vector <int> (m + 10));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j]) {
                ans += max(0LL, v[i][j] - v[i - 1][j]);
                ans += max(0LL, v[i][j] - v[i][j - 1]);
                ans += max(0LL, v[i][j] - v[i + 1][j]);
                ans += max(0LL, v[i][j] - v[i][j + 1]);
                ans++;
            }
        }
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