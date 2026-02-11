#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (n % (m + 1) == 0) {
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
    }
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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