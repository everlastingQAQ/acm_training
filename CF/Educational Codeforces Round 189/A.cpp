#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 x, y;
    cin >> x >> y;
    if (y == 2 * x) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
}

int main ()
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