#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector <vector <int> > dp(2, vector <int> (5, -INF));
    dp[0][0] = 0;

    vector <int> val = {1, 10, 100, 1000, 10000};

    for (int i = n; i >= 1; i--) {
        vector <vector <int> > ndp(2, vector <int> (5, -INF));
        for (int mx = 0; mx <= 4; mx++) {
            for (int j = 0; j <= 4; j++) {
                int add = (j < mx ? -val[j] : val[j]);
                int nmx = max(j, mx);
                if (j == s[i] - 'A') {
                    ndp[0][nmx] = max(ndp[0][nmx], dp[0][mx] + add);
                    ndp[1][nmx] = max(ndp[1][nmx], dp[1][mx] + add);
                }else {
                    ndp[1][nmx] = max(ndp[1][nmx], dp[0][mx] + add);
                }
            }
        }
        dp = ndp;
    }

    int ans = -INF;
    for (int used = 0; used <= 1; used++) {
        for (int mx = 0; mx <= 4; mx++) {
            ans = max(ans, dp[used][mx]);
        }
    }

    cout << ans << '\n';
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