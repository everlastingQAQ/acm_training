#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int x, y;
    cin >> x >> y;
    if (y == x + 1 || ((x - y + 1) % 9 == 0 && x >= y)) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
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