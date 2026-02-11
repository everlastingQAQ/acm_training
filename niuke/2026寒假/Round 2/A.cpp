#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, c; cin >> a >> b >> c;
    int mx = max({a, b, c});
    int mn = min({a, b, c});
    if (mx >= mn + 2) {
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
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