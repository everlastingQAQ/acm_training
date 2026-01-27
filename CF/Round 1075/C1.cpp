#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> ans(n + 1);
    ans[n] = 1;
    map <int, int> mp;
    mp[1] = true;
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = 1 ^ i;
        mp[ans[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i] == false) {
            ans[1] = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}   
    
signed main ()
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