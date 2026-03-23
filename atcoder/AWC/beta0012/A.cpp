#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 t;
    cin >> t;
    vector <i64> h(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] <= t) ans += c[i];
    }
    cout << ans << '\n';
}   
    
int main ()
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