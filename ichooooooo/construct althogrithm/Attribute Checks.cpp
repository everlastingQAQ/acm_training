#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e12;

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <int> dp (m + 1);
    vector <int> cf (m + 5);

    int x = 0;
    for (int i = 0; i < n; i ++) {
        int p; cin >> p;
        if (p == 0) {
            x++;
            // dp[x] = 0;
            continue;
        }

        if (p > 0) {
            if (x < p) continue;
            cf[p]++;
            cf[x + 1]--;
            // for (int j = x; j >= p; j --) {
            //     dp[j] = max (dp[j], dp[j] + 1);
            // }
        } else {
            if (x < abs (p)) continue;
            cf[0]++;
            cf[(x - abs(p)) + 1]--;
            // for (int j = 0; j <= (x - abs (p)); j ++) {
            //     dp[j] = max (dp[j], dp[j] + 1);
            // }
        }
    }

    for (int i = 0; i <= m; i ++) {
        if (i == 0) dp[i] = cf[i];
        else {
            dp[i] = dp[i - 1] + cf[i];
        }
    }

    int mx = 0;
    for (int i = 0; i <= m; i ++) {
        mx = max (mx, dp[i]);
    }

    cout << mx << '\n';
}

signed main () {
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) ovo();
}