#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x;
    cin >> n >> x;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (mp[x - t]) {
            cout << mp[x - t] << ' ' << i << '\n';
            return;
        }
        mp[t] = i;
    }
    cout << "IMPOSSIBLE\n";
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