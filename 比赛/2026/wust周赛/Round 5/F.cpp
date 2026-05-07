#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <i64> > v(n + 10, vector <i64> (m + 10));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <i64> > dp(n + 10, vector <i64> (m + 10, -1e18));
    map <array <int, 2>, vector <i64> > mp;
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        i64 cur = dp[i - 1][i - 1];
        auto t = mp[{i - 1, i - 1}];

        for (int j = i; j <= m; j++) {
            dp[i][j] = cur + v[i][j];
            mp[{i, j}] = t;
            mp[{i, j}].push_back(j);

            if (dp[i - 1][j] > cur) {
                t = mp[{i - 1, j}];
                cur = dp[i - 1][j];
            }else if (dp[i - 1][j] == cur) {
                t = min(t, mp[{i - 1, j}]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         for (auto c : mp[{i, j}]) {
    //             cout << c << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    i64 ans = -1e18;
    vector <i64> anss;
    for (int i = n; i <= m; i++) {
        ans = max(ans, dp[n][i]);
    }

    bool ok = false;
    for (int i = n; i <= m; i++) {
        if (dp[n][i] == ans) {
            if (!ok) {
                anss = mp[{n, i}];
                ok = true;
            }else {
                if (mp[{n, i}] < anss) {
                    anss = mp[{n, i}];
                }
            }
        }
    }

    cout << ans << '\n';
    for (auto x : anss) {
        cout << x << ' ';
    }
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