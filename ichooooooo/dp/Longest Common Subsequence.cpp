#include<bits/stdc++.h>
using namespace std;
#define int long long

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <int> a (n + 1), b (m + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i ++) {
        cin >> b[i];
    }

    vector <vector <int> > dp (n + 1, vector <int> (m + 1));
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << '\n';
}

signed main () {
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) ovo();
}