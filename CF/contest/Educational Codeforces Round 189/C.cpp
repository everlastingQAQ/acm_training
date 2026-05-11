#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <char, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1];
    }

    if (n == 1) {
        cout << (v[1][0] == v[1][1] ? 0 : 1) << '\n';
        return;
    }

    vector <int> dp(n + 1);
    dp[1] = (v[1][0] == v[1][1] ? 0 : 1);

    if (n >= 2) {
        dp[2] = dp[1] + (v[2][0] == v[2][1] ? 0 : 1);
        int cnt = 0;
        if (v[2][0] != v[1][0]) cnt++;
        if (v[2][1] != v[1][1]) cnt++;
        dp[2] = min(dp[2], cnt);
    }

    for (int i = 3; i <= n; i++) {
        int c1 = dp[i - 1] + (v[i][0] == v[i][1] ? 0 : 1);
        int c2 = dp[i - 2];
        if (v[i][0] != v[i - 1][0]) c2++;
        if (v[i][1] != v[i - 1][1]) c2++;
        dp[i] = min(c1, c2);
    }

    cout << dp[n] << '\n';
}

int main ()
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