#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll l, r;

void solve ()
{
    cin >> l >> r;
    if (l == 1) {
        if (r >= 4) {
            cout << "NO" << '\n';
            return;
        }else if (r == 3) {
            cout << "YES" << '\n';
            cout << "3 2 1" << '\n';
        }else if (r == 2) {
            cout << "YES" << '\n';
            cout << "2 1" << '\n';
        }else if (r == 1) {
            cout << "YES" << '\n';
            cout << 1 << '\n';
        }
        return;
    }

    if (r - l + 1 == 3) {
        if (l % 2 != 0) {
            cout << "YES" << '\n';
            cout << r << ' ' << r - 1 << ' ' << l << '\n';
        }else {
            cout << "NO" << '\n';
        }
        return;
    }

    if (r - l + 1 > 3) {
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
        if (r == l) {
            cout << r << '\n';
        }else {
            cout << r << ' ' << l << '\n';
        }
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