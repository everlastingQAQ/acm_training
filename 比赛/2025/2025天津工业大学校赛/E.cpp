#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    vector <int> c(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = abs(a[i] - b[i]);
    }

    int ans = c[1];
    for (int i = 2; i <= n; i++) {
        ans = gcd(ans, c[i]);
    }

    cout << ans << '\n';
    
}  
    
int32_t main ()
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