#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    i64 r;
    cin >> n >> m >> r;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 t;
        cin >> t;
        ans += t;
    }
    ans += m * r;
    cout << ans << '\n';
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