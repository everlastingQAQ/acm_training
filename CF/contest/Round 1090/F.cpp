#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int x, y;
    cin >> x >> y;
    if (x > y) {
        cout << "NO\n";
        return;
    }
    if ((!((x + y) & 1) && x == 0) || (((x + y) & 1) && y == 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int cur = 2;
    int t = x;
    if (!((x + y) & 1)) t--;
    for (int i = 0; i < t; i++) {
        cout << 1 << ' ' << cur << '\n';
        cur++;
        if (cur > x + y) break;
        cout << cur - 1 << ' ' << cur << '\n';
        cur++;
    }
    while (cur <= x + y) {
        cout << 1 << ' ' << cur << '\n';
        cur++;
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