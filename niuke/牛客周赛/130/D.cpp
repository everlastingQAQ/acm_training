#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b;
    cin >> a >> b;
    if (b == 3) {
        cout << 1 << ' ' << 3 << '\n';
    }else if (b == 0) {
        if (a & 1) {
            cout << 1 << ' ' << 11 << '\n';
        }else {
            cout << 10 << ' ' << 11 << '\n';
        }
    }else if (b == 9) {
        if (a & 1) {
            cout << 10 << ' ' << 11 << '\n';
        }else {
            cout << 1 << ' ' << 11 << '\n';
        }
    }else if (b == 6) {
        cout << 2 << ' ' << 3 << '\n';
    }else {
        cout << b << ' ' << 9 << '\n';
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