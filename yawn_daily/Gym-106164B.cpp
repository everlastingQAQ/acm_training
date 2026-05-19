#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        if (m & 1) cout << "2 1\n";
        else cout << "1 2\n";
        return;
    }

    if (m >= n) {
        for (int i = n; i >= 1; i--) {
            cout << i << " \n"[i == 1];
        }
        return;
    }
    while (m--) {
        cout << n-- << ' ';
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " \n"[i == n];
    }
}   

int32_t main ()
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