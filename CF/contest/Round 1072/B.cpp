#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int s, k, m; cin >> s >> k >> m;
    if (s <= k) {
        if (m >= k) {
            int t = m / k;
            int ans = s - (m - t * k); 
            cout << max(0LL, ans) << '\n';
        }else if (m < k) {
            int ans = s - m;
            cout << max(0LL, ans) << '\n';
        }
    }else if (s > k) {
        int t = m / k;
        if (t & 1) {
            int left = k - (m - t * k);
            cout << left << '\n';
        }else {
            int left = s - (m - t * k);
            cout << left << '\n';
        }
    }
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}