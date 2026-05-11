#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 x, y;
    cin >> x >> y;
    if (x + y >= 0 && x >= 2 * y && x >= -4 * y && x != 1 && (x + y) % 3 == 0) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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