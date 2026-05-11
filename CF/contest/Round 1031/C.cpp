#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <char> > v(n + 1, vector <char> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > s(n + 1, vector <int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + (v[i][j] == 'g');
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == '.') {
                ans = min(ans, s[min(i + k - 1, n)][min(j + k - 1, m)]
                      - s[min(i + k - 1, n)][max(j - k, 0)]
                      - s[max(i - k, 0)][min(j + k - 1, m)] 
                      + s[max(i - k, 0)][max(j - k, 0)]);
            }
        }
    }
    cout << s[n][m] - ans << '\n';
} 
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 