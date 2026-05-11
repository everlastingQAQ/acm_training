#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int ans = 0;
    int mn = 1e11;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mn = min(mn, v[i]);
        ans += mn;
    }

    int cur = v[1] + min(v[1], v[2]); 
    ans = min(ans, cur);
    cout << ans << '\n';
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