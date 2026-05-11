#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        if (v[i][1] == '1') ok = true;
        for (int j = 1; j <= m; j++) {
            if (!ok && v[i][j] == '1') vis[i][j] = 1;
            else if (v[i][j] == '0') ok = false;
        }
    }

    for (int j = 1; j <= m; j++) {
        bool ok = false;
        if (v[1][j] == '1') ok = true;
        for (int i = 1; i <= n; i++) {
            if (!ok && v[i][j] == '1' && vis[i][j] == 1) {
                cout << "NO" << '\n';
                return;
            }
            if (v[i][j] == '0') ok = false;
        }
    }

    cout << "YES" << '\n';
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