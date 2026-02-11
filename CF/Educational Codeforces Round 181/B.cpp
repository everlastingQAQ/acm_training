#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, k;
    cin >> a >> b >> k;
    int t = gcd(a, b);
    a /= t;
    b /= t;
    if (max(a, b) <= k) {
        cout << 1 << '\n';
    }else {
        cout << 2 << '\n';
    }
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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