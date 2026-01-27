#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    int ans = 0;
    for (char c : s) {
        if (c == 'i' || c == 'j') ans++;
    }
    cout << ans << '\n';
}   
    
signed main ()
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