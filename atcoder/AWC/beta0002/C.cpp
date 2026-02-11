#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <array <int, 2> > v(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        if (v[i][0] >= m) {
            ans = max(ans, 0LL);
            continue;
        }
        int t = (m - v[i][0]) / v[i][1];
        if (v[i][1] * t < m - v[i][0]) t++;
        ans = max(ans, t);
    }
    cout << ans;
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