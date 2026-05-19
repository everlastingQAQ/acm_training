#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (3 * b <= c) {
        cout << a * b << '\n';
    }else if (3 * b > c) {
        cout << a / 3 * c + min(c, a % 3 * b) << '\n';
    }
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