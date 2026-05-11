#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    vector <int> res(n * m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cnt = 0;
            res[v[i][j]] = max(res[v[i][j]], 1);
            if (i < n && v[i + 1][j] == v[i][j]) cnt++;
            if (j < m && v[i][j + 1] == v[i][j]) cnt++;
            if (cnt >= 1) res[v[i][j]] = 2;
        }
    }

    i64 ans = 0;
    int mx = 0;
    for (int i = 1; i <= n * m; i++) {
        ans += res[i];
        mx = max(mx, res[i]);
    }
    cout << ans - mx << '\n';
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