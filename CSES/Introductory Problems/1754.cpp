#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 a, b;
    cin >> a >> b;
    if (a == b) {
        if (a % 3 != 0) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
        return;
    }

    if (a < b) swap(a, b);

    if (b * 2 < a) {
        cout << "NO\n";
        return;
    }

    i64 t = b - (a - b);

    if (t % 3 != 0) {
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