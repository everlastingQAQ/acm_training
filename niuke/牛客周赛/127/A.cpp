#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int a, b, c; cin >> a >> b >> c;
    if (a + b == c || a - b == c || a * b == c || (a / b == c && a % b == 0)) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
    }
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