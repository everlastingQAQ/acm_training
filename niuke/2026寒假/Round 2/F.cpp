#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;

    int pos = 31;
    for (int i = 31; i >= 0; i--) {
        if (n >> i & 1) {
            pos = i + 1;
            break;
        }
    }

    int a1 = (n << pos);
    int a2 = a1 + n;
    cout << a1 << ' ' << a2 << '\n';
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