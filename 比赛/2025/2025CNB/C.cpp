#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, a;

void solve ()
{
    cin >> n >> a;
    if (n > 15) {
        cout << "error" << '\n';
        return;
    }
    if (a == 0) {
        if (n < 10) {
            cout << "cool" << '\n';
        }else {
            cout << "hot" << '\n';
        }
    }else {
        if (n < 10) {
            cout << "cold" << '\n';
        }else {
            cout << "warm" << '\n';
        }
    }
}

int main ()
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