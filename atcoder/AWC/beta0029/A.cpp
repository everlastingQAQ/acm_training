#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, p, b, k;
    cin >> n >> p >> b >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	int t;
    	cin >> t;
    	ans += t * (t >= k ? b + p : p);
    }
    cout << ans << '\n';
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