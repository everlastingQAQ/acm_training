#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    int ans = -1;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (!ok && t == k) {
            ans = i;
            ok = true;
        }
    }
    cout << ans;
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