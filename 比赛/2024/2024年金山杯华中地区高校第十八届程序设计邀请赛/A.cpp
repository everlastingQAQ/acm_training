#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
  
void solve ()
{
    int n;
    cin >> n;
    if (n < 240) {
        cout << 3 << '\n';
    }else {
        cout << 2 << '\n';
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}