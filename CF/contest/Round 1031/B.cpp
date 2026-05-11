#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((abs(x1 - x2) % a == 0 && x1 != x2)|| (abs(y1 - y2) % b == 0 && y1 != y2)) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
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