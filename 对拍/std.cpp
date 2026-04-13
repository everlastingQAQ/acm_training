#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    int t = n % 10;
    if (t == 1 || t == 3 || t == 7 || t == 9) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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