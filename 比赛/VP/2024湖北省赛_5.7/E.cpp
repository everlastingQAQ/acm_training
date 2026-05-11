#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    int a1 = (n - x) * a + x * b;
    cout << a1 << '\n';
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