#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int m, n; cin >> m >> n;
    cout << __builtin_popcount(m ^ n) << '\n';
}   
    
signed main ()
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