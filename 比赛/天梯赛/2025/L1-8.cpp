#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    int mx = 0;
    int mxx = 0, mxy = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            mx = max(mx, v[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == mx) {
                mxx = i, mxy = j;
            }
        }
    }

    vector <int> x(n + 1);
    vector <int> y(m + 1);
    for (int o = 1; o <= k; o++) {
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mx = max(mx, v[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i][j] == mx) {
                    mxx = i, mxy = j;
                }
            }
        }
        
        x[mxx] = true;
        y[mxy] = true;
        for (int j = 1; j <= n; j++) {
            v[j][mxy] = 0;
        }
        for (int j = 1; j <= m; j++) {
            v[mxx][j] = 0;
        }
    }

    int lasty = 0;
    for (int i = m; i >= 1; i--) {
        if (!y[i]) {
            lasty = i;
            break;
        } 
    }

    for (int i = 1; i <= n; i++) {
        if (x[i]) continue;
        for (int j = 1; j <= m; j++) {
            if (y[j]) continue;
            if (j == lasty) cout << v[i][j];
            else cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}   
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 