#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll x, y, p1, p2;

void solve ()
{
    cin >> x >> y >> p1 >> p2;
    if (x > y) {
        cout << 'A' << '\n';
        return;
    }else if (x < y) {
        cout << 'B' << '\n';
        return;
    }else {
        if (p1 < p2) {
            cout << 'A' << '\n';
        }else if (p1 > p2) {
            cout << 'B' << '\n';
        }else {
            cout << 'C' << '\n';
        }
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}