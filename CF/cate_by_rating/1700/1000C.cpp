#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }
    vector <int> ans(n + 1);
    int cur = 0;
    int pre = 0;
    for (auto [x, y] : mp) {
        ans[cur] += x - pre;
        pre = x;
        cur += y;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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