#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    if (n == 1 || n == 2 || n == 4) {
        cout << "-1" << '\n';
        return;
    }

    if (!(n & 1)) {
        n -= 3;
        cout << "1 2 1 "; 
    }
    
    int mx = n / 2 + 1;
    for (int i = 1; i <= mx; i++) {
        cout << i << ' ';
    }
    for (int i = mx - 1; i >= 1; i--) {
        cout << i << " \n"[i == 1];
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