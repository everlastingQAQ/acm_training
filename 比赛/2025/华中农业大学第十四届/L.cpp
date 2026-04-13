#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 k, x, y;
    cin >> k >> x >> y;
    if (y - x < (1LL << (k - 1))) {
        cout << x << '\n';
    }else {
        cout << x + 1 << '\n';
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