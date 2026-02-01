#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k; cin >> n >> m >> k;
    vector <vector <int> > v(n + 1, vector <int> (m + 1, 0));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i % 3 == 2 || n % 3 == 1 && i == n) && (j % 3 == 2 || m % 3 == 1 && j == m)) {
                v[i][j] = 1;
                cnt++;
            }
        }               
    }

    cnt = n * m - cnt - k;
    if (cnt < 0) {
        cout << -1 << '\n';
        return;
    }

    if (cnt > 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i][j] == 0) {
                    v[i][j] = 1;
                    cnt--;
                }
                if (cnt == 0) break;
            }
            if (cnt == 0) break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
    
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