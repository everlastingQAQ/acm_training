#include<bits/stdc++.h>
using namespace std;
#define int long long

void ovo() {
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();

    vector <vector <int> > dp (n + 1, vector <int> (m + 1));
    
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= m; j ++) {
        dp[0][j] = j;    
    }


    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min ({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
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