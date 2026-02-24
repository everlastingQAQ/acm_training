#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    char c;
    cin >> c;
    if (c == 'A') {
        cout << "red";
    }else if (c == 'B') {
        cout << "orange";
    }else if (c == 'C') {
        cout << "blue";
    }else {
        cout << "green";
    }
}   
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/