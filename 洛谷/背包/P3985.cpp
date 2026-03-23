#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, w;
    cin >> n >> w;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    vector <vector <int> > dp(w + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= v[i][0]; j--) {
            for (int k = n; k >= 1; k--) {
                dp[j][k] = max(dp[j - v[i][0]][k - 1] + v[i][1], dp[j][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= )
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