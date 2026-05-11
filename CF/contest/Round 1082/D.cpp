#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    if (k < n || k >= 2 * n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    while (k <= 2 * n - 2) {
        cout << n << ' ' << n << ' ';
        n--;
        k--;
    }

    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
    }else {
        cout << 1 << ' ' << 2 << ' ';
        for (int i = 3; i <= n; i++) {
            cout << i << ' ' << i - 2 << ' ';
        }
        cout << n - 1 << ' ' << n << '\n';
    }
}   
    
int main ()
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