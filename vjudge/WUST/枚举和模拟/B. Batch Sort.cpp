#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                swap(v[k][i], v[k][j]);
            }
            bool ok = true;
            for (int k = 1; k <= n; k++) {
                int cnt = 0;
                for (int l = 1; l <= m; l++) {
                    if (v[k][l] != l) cnt++;
                    if (cnt > 2) ok = false;
                    if (!ok) break; 
                }
                if (!ok) break;
            }
            if (ok) {
                cout << "YES" << '\n';
                return;
            }
            for (int k = 1; k <= n; k++) {
                swap(v[k][i], v[k][j]);
            }
        }
    }

    cout << "NO" << '\n';
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