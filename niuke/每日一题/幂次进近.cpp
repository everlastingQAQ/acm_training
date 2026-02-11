#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    long double n, k; cin >> n >> k;
    int t = pow(n, (long double)1.0 / k);
    if (abs(n - pow(t, k)) < abs(n - pow(t + 1, k))) {
        cout << t << '\n';
    }else cout << t + 1 << '\n';
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