#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    
    for (int ans = 0; ans < 512; ans++) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            bool ok1 = false;
            for (int j = 1; j <= m; j++) {
                if (((a[i] & b[j]) | ans) == ans) {
                    ok1 = true;
                    break;
                }
            }
            if (!ok1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << ans << '\n';
            return;
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