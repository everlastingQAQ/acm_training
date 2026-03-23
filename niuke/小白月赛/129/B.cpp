#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

void solve ()
{
    i64 n, k;
    cin >> n >> k;
    int t = k * 2 + 1;
    i64 ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * t % mod) % mod;
    }
    cout << ans << '\n';
}   
    
int main ()
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