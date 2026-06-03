#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= c; i++) {
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
    }
    using arr2 = array <int, 2>;
    vector <vector <arr2> > a(n + 1, vector <arr2> (m + 1));
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == 1) cur = j;
            a[i][j][0] = cur;
        }
        cur = n;
        for (int j = m; j >= 1; j--) {
            if (v[i][j] == 1) cur = j;
            a[i][j][1] = cur;
        }
    }
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