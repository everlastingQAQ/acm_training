#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (n != 1 && m != 1) {
        cout << "-1\n";
        return;
    }
    if (n == 1 && m == 1) {
        cout << -1 << '\n';
        return;
    }

    if (n == 1) {
        cout << 0;
        for (int i = 2; i <= m; i++) {
            cout << 1;
        }
    }else {
        cout << 0 << '\n';
        for (int i = 2; i <= n; i++) {
            cout << 1 << '\n';
        }
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
