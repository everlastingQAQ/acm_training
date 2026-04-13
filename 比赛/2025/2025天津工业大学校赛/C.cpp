#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << n * m << '\n';
        return;
    }

    if (n == 2) {
        if (m % 4 == 0) {
            cout << m / 4 * 4 << '\n';
        }else if (m % 4 == 1) {
            cout << m / 4 * 4 + 2 << '\n';
        }else if (m % 4 == 2) {
            cout << (m / 4 + 1) * 4 << '\n';
        }else if (m % 4 == 3) {
            cout << (m / 4 + 1) * 4 << '\n';
        }
        return;
    }else if (m == 2) {
        if (n % 4 == 0) {
            cout << n / 4 * 4 << '\n';
        }else if (n % 4 == 1) {
            cout << n / 4 * 4 + 2 << '\n';
        }else if (n % 4 == 2) {
            cout << (n / 4 + 1) * 4 << '\n';
        }else if (n % 4 == 3) {
            cout << (n / 4 + 1) * 4 << '\n';
        }
        return;
    }

    if ((n * m) & 1) {
        cout << n * m / 2 + 1 << '\n';
    }else {
        cout << n * m / 2 << '\n';
    }
} 
    
int32_t main ()
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