#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n, k; cin >> n >> k;
    if (n == 1) {
        cout << -1 << '\n';
        return;
    }else if (n == 2) {
        if (k == 0) {
            cout << 1 << ' ' << 1 << '\n';
        }else {
            cout << -1 << '\n';
        }
        return;
    }

    if (k == 0) {
        if (n & 1) {
            cout << -1 << '\n';
        }else {
            for (int i = 1; i <= n / 2; i++) {
                cout << i << ' ' << i << ' ';
            }
        }
        return;
    }

    if ((n - k) & 1) {
        cout << -1 << '\n';
        return;
    }

    // if (n & 1) {
        for (int i = 1; i <= n - k + 1; i++) {
            cout << 1 << ' ';
        }
        int a = 2;
        for (int i = n - k + 2; i <= n; i++) {
            cout << a++ << ' ';
        }
    // }else {

    // }
    // for (int i = 0; i < 3; i++) cout << 1 << ' ';
    // for (int i = 2; i <= n - 2; i++) {
    //     cout << i << ' ';
    // }
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}