#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (!((b + c) & 1)) cout << 1 << ' ';
    else cout << 0 << ' ';

    if (!((a + c) & 1)) cout << 1 << ' ';
    else cout << 0 << ' ';
    
    if (!((b + a) & 1)) cout << 1 << ' ';
    else cout << 0 << ' ';
    cout << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}