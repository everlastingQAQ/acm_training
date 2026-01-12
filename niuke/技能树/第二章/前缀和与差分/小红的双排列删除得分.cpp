#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init() 
{

}

void solve ()
{
    int n; cin >> n;
    vector <int> v(2 * n + 1), s(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }   

    vector <int> pos(n + 1, 0);
    vector <int> dp(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        if (pos[v[i]] == 0) {
            dp[i] = dp[i - 1];
            pos[v[i]] = i;
        }else {
            int t = dp[pos[v[i]] - 1] + s[i] - s[pos[v[i]] - 1];
            dp[i] = max(dp[i - 1], t);
        }
    }
    
    cout << dp[2 * n] << '\n';
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}