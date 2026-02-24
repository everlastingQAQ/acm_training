#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int m, n, z;
    cin >> m >> n >> z;
    int t = m + n;
    int tt = z / t;
    if (z % t == 0) {
        cout << 1;
    }else {
        int lft = z - tt * t;
        if (lft <= m) {
            cout << 0;
        }else {
            cout << 1;
        }
    } 
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