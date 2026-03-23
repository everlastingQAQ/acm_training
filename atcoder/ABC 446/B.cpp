#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        int ans = 0;
        bool ok = false;
        for (int i = 1; i <= l; i++) {
            int t;
            cin >> t;
            if (!ok && !mp[t]) {
                mp[t] = true;
                ans = t;
                ok = true;
            }
        }
        cout << ans << '\n';
    }
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