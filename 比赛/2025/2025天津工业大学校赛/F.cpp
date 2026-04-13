#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << "Liang";
    }else if (a < b) {
        cout << "Chuang";
    }else {
        cout << "Pingju";
    }
} 
    
int32_t main ()
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