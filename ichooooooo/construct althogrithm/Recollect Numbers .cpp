#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    if (k < n || k > ( 2 * n - 1)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        while (k < 2 * n - 1) {
            cout << n << ' ' << n << ' ';
            n--; k--;
        }

        if (n == 1) {
            cout << 1 << ' ' << 1 << '\n';
        } else {
            cout << 1 << ' ' << 2 << ' ';
            for (int i = 3; i <= n; i ++) {
                cout << i << ' ' << i - 2 << ' ';
            }
            cout << n - 1 << ' ' << n << '\n';
        }
    }
} 
    
signed main ()
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