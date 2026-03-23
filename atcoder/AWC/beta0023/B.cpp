#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        ans += a;
        ans -= b;
        if (ans < 0) ans = 0;
    }
    i64 x;
    cin >> x;
    cout << ans + x << '\n';
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