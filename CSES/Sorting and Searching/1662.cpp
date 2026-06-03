#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    int ans = 0;
    int sum = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum = ((sum + v[i]) % n + n) % n;
        ans += mp[sum];
        mp[sum]++;
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