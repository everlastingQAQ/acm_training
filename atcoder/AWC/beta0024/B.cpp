#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    int ans = k;
    map <int, int> mp;
    for (int i = 1; i <= k; i++) {
        mp[i] = true;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (mp[a] && !mp[b]) {
            ans++;
            mp[b] = true;
        }else if (!mp[a] && mp[b]) {
            ans++;
            mp[a] = true;
        }
    }
    cout << ans << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 