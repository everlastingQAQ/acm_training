#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int hm, tm, n;
    cin >> hm >> tm >> n;
    vector <int> h(n + 1), t(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> t[i] >> k[i];
    }

    vector <vector <int> > dp(hm + 1, vector <int> (tm + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = hm; j >= h[i]; j--) {
            for (int l = tm; l >= t[i]; l--) {
                dp[j][l] = max(dp[j - h[i]][l - t[i]] + k[i], dp[j][l]);
            }
        }
    }

    cout << dp[hm][tm] << '\n';
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