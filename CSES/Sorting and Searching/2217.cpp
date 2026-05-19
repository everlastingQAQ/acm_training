#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> pos(n + 1), v(n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    for (int i = 2; i <= n; i++) {
        ans += (pos[i - 1] > pos[i]);  
    }

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        
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