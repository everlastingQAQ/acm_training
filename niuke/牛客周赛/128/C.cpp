#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    int t = n - n / 2;

    vector <int> vis(n + 1, 0);
    int x = t - 1;
    if (x & 1) {
        for (int i = t; i <= t + x / 2 + 1; i++) {
            vis[i] = true;
        }
        for (int i = t - 1; i >= t - x / 2; i--) {
            vis[i] = true;
        }
    }else {
        for (int i = t + 1; i <= t + x / 2; i++) {
            vis[i] = true;
        }
        for (int i = t - 1; i >= t - x / 2; i--) {
            vis[i] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[v[i]]) v[i] = t;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " \n"[i == n];
    }
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