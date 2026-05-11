#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += (v[i] / x) * y;
    } 

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = sum - (v[i] / x) * y + v[i];
        ans = max(ans, cur);
    }

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