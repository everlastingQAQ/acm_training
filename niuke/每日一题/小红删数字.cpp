#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int mod = 1e9 + 7;

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (n > 1) v[i] %= 10;
    }

    reverse(v.begin() + 1, v.end());

    vector <vector <int> > dp(n + 1, vector <int> (10));
    dp[1][v[1]]++;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][(v[i] + j) % 10] = (dp[i][(v[i] + j) % 10] + dp[i - 1][j]) % mod;
            dp[i][(v[i] * j) % 10] = (dp[i][(v[i] * j) % 10] + dp[i - 1][j]) % mod;
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << dp[n][i] % mod << " \n"[i == 9];
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