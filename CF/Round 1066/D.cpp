#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> v(n);
    for (int &x : v) {
        cin >> x;
    }
    ranges::sort(v);
    
    int x = v[(n + 1) / 2 - 1];
    x = max(x, l);
    x = min(x, r);

    int ans = 0;
    for (int t : v) {
        ans += abs(t - x);
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