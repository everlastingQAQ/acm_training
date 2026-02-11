#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int mx = ranges::max(v | views::drop(1));
    int ans = mx * n;
    if (v[1] != mx) {
        ans -= mx - v[1];
    }
    if (v[n] != mx) {
        ans -= mx - v[n];
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