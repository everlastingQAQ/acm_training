#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    int k; cin >> k;
    for (int i = 2; i <= n; i++) {
        int t; cin >> t;
        k = gcd(k, t);
    }
    cout << k * n << '\n';

}   
    
int32_t main ()
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