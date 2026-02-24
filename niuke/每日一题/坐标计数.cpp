#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (x2 - x1 + 1) * (y2 - y1 + 1) << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/