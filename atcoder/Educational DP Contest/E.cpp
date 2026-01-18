#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int N = 1000000;

void solve ()
{
    int n, w; cin >> n >> w;
    vector <array<int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1] >> v[i][0];
    }

    vector <int> dp(N + 1, 1e11);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = N; j >= v[i][0]; j--) {
            dp[j] = min(dp[j], dp[j - v[i][0]] + v[i][1]);
        }
    }

    for (int i = N; i >= 1; i--) {
        if (dp[i] <= w) {
            cout << i << '\n';
            return;
        }
    }
}   

signed main ()
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