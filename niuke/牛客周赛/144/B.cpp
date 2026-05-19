#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
    }else if (n == 2) {
        cout << 1 << ' ' << 2 << '\n';
        cout << 3 << ' ' << 4 << '\n';
    }else if (n == 3) {
        cout << 1 << ' ' << 2 << ' ' << 3 << '\n';
        cout << 5 << ' ' << 4 << ' ' << 6 << '\n';
        cout << 7 << ' ' << 8 << ' ' << 9 << '\n';
    }else {
        cout << -1 << '\n';
    }
}

int32_t main()
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