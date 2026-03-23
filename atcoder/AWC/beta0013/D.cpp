#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <i64> > v(m + 1, vector <i64> (n + 1));
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            cin >> v[i][j];
        }
    }
    
    i64 ans = 0;
    for (int j = 1; j <= m; j++) {
        sort(v[j].begin() + 1, v[j].end());
        for (int i = 1; i <= n; i++) {
            ans += v[j][i] * (i - 1) - v[j][i] * (n - i); 
        }   
    }

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