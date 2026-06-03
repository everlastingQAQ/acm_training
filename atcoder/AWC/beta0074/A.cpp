#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x;
    cin >> n >> x;
    int t = n / x;
    int tt = n % x;
    if (tt >= x / 2 && tt > 0) t++;
    cout << t << '\n';
}   
    
int32_t main ()
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