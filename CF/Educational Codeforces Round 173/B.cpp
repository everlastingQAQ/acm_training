#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, d;
    cin >> n >> d;
    cout << 1 << ' ';
    if (n >= 3 || d % 3 == 0) {
        cout << 3 << ' ';
    }
    if (d == 5) {
        cout << 5 << ' ';
    }
    if (n >= 3 || d == 7) {
        cout << 7 << ' ';
    }
    if (n >= 6 || d == 9 || (n >= 3 && d % 3 == 0)) {
        cout << 9 << ' ';
    }
    cout << '\n';
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