#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

void solve ()
{   
    vector <int> v(n + 1);
    map <int, int> mp;
    int ans = 0;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        mp[t]++;
        if (!ok && mp[t] == (n + 1) / 2) {
            ans = t;
            ok = true;
        }
    }
    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    while (cin >> n) {
        solve();
    }
    return 0;
} 