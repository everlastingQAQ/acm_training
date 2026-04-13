#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int x;
    cin >> x;
    if (x == 142857) {
        cout << 1 << '\n';
    }else if (x == 285714) {
        cout << 2 << '\n';
    }else if (x == 428571) {
        cout << 3 << '\n';
    }else if (x == 571428) {
        cout << 4 << '\n';
    }else if (x == 714285) {
        cout << 5 << '\n';
    }else {
        cout << 6 << '\n';
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