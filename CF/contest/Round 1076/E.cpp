#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin() + 1, v.end());
    v.erase(unique(v.begin() + 1, v.end()), v.end());
    int m = v.size();

    vector <int> ans(n + 1, 1e15);

    for (int i = 1; i < m; i++) {
        ans[v[i]] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int t = i * v[j];
            if (t > n) break;
            ans[t] = min(ans[t], ans[i] + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1e15) {
            cout << -1 << " \n"[i == n];
        }else {
            cout << ans[i] << " \n"[i == n];
        }
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