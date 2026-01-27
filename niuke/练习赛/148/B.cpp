#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(n + 1), a(n + 1);  
    for (int i = 1; i <= n; i++) cin >> v[i], a[i] = v[i] * i;
    vector <int> vis(n + 1, 0);
    int aa = accumulate(a.begin() + 1, a.end(), 0LL), vv = accumulate(v.begin() + 1, v.end(), 0LL);
    
    auto dfs = [&] (int u, int cnt, auto self) -> void {
        if (cnt == k) {
            int a1 = 0, v1 = 0;
            for (int i = 1; i <= n; i++) {
                if (vis[i]) continue;
                a1 += a[i];
                v1 += v[i];
            }
            if (a1 * vv == aa * v1) {
                cout << "Yes" << '\n';
                exit(0);
            }
            return;
        }
        if (u > n) return;
        vis[u] = true;
        self(u + 1, cnt + 1, self);
        vis[u] = false;
        self(u + 1, cnt, self);
    };

    dfs(1, 0, dfs);

    cout << "No" << '\n'; 
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