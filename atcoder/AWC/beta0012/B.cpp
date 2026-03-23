#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 t, c, d;
    cin >> t >> c >> d;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 cur;
        cin >> cur;
        if (cur >= t) ans += min(c, d); 
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