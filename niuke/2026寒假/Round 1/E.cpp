#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int ans = k + v[1];
    for (int i = 2; i <= n; i++) {
        ans = max(ans, v[i] + v[i - 1]);
    }
    ans = max(ans, k + v[n]);
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