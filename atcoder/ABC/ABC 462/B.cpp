#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            int x;
            cin >> x;
            ans[x].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i].empty()) {
            cout << 0 << '\n';
        }else {
            cout << ans[i].size() << ' ';
            for (auto x : ans[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        
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