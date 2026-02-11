#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, l, r;
    cin >> n >> l >> r;
    int pos = -1;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t >= l && t <= r) {
            if (t > mx) {
                mx = t;
                pos = i + 1;
            }
        }
    }
    cout << pos << '\n';
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