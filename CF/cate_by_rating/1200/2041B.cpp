#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int ans = 0;
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    while ((ans + 1) * (2 + ans) / 2 <= sum) {
        ans++;
    }
    cout << ans << '\n';
}   

int32_t main ()
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