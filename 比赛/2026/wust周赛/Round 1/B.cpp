#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{	
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(m + 1, vector <int> (n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        map <int, int> mp;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (v[j][k] == i) {
                    if (k == n) mp[v[j][k - 1]] = true;
                    else if (k == 1) mp[v[j][k + 1]] = true;
                    else {
                        mp[v[j][k - 1]] = true;
                        mp[v[j][k + 1]] = true;
                    }
                }
            }
        }

        for (int l = 1; l <= n; l++) {
            if (l == i) continue;
            if (!mp[l]) ans++;
        }
    }

    cout << ans / 2 << '\n';
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