#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int q = 0;

void solve ()
{   
    vector <array<int, 3> > v;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
        v.push_back({a, c, b});
        v.push_back({b, a, c});
        v.push_back({b, c, a});
        v.push_back({c, a, b});
        v.push_back({c, b, a});
    }
    sort(v.begin(), v.end());
    vector <int> dp(6 * n);
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        dp[i] = v[i][2];
        for (int j = i - 1; j >= 0; j--) {
            if (v[i][0] > v[j][0] && v[i][1] > v[j][1]) {
                dp[i] = max(dp[i], dp[j] + v[i][2]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << "Case " << q << ": maximum height = " << ans << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    while (cin >> n) {
        if (n == 0) break;
        q++;
        solve();
    }
    return 0;
} 