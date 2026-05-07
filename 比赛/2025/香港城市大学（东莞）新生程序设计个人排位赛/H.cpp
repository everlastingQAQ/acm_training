#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <char> > v(n + 1, vector <char> (3));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[j][i];
        }
    }
    vector <vector <int> > dp(n + 1, vector <int> (3));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + (v[i][0] == '1' && v[i][1] == '1');
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + (v[i][0] == '1' && v[i][2] == '1');
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + (v[i][1] == '1' && v[i][2] == '1'); 
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
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