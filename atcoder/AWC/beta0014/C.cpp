#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve ()
{
    i64 g, m, d, k, v;
    cin >> g >> m >> d >> k >> v;
    if ((i128)d * (i128)k <= (i128)g) {
        i128 l1 = (i128)v * (i128)(g - d * k + k);
        i128 r1 = m - g;
        if (l1 <= r1) {
            cout << "Yes";
        }else {
            cout << "No";
        }
    }else {
        i128 l1 = (i128)v * (i128)g;
        i128 r1 = (i128)d * (i128)(m - g);
        if (l1 <= r1) {
            cout << "Yes";
        }else {
            cout << "No";
        }
    }
    
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