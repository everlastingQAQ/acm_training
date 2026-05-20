#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    map <int, int> mp;
    int l = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[v[i]]) {
            l = max(l, mp[v[i]]);
        }
        ans += i - l;
        mp[v[i]] = i;
    }
    cout << ans << '\n';
    
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