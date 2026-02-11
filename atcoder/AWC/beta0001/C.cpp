#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (int &x : v) cin >> x;
    ranges::sort(v);

    int ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += v[i];
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