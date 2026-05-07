#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int x, y;
    cin >> x >> y;
    if ((x & 1) && (y & 1)) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
}

int main ()
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