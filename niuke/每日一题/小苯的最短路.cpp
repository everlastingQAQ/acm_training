#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    int t = n % 4;
    if (t == 0) {
        cout << n << '\n';
    }else if (t == 1) {
        cout << 0 << '\n';
    }else if (t == 2) {
        cout << n + 1 << '\n';
    }else if (t == 3) {
        cout << 1 << '\n';
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