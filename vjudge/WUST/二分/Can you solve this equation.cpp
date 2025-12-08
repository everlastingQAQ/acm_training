#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1000000;
const double eps = 1e-10;
const ll mod = 998244353;
double y;

double check (double x)
{
    return 8.0 * x * x * x * x + 7.0 * x * x * x + 2.0 * x * x + 3.0 * x - y + 6;
}

void solve ()
{
    cin >> y;

    if (y > 807020306 || y < 6) {
        cout << "No solution!" << '\n';
        return;
    }

    double l = 0, r = 100;

    while (r - l > eps) {
        double mid = l + (r - l) / 2;
        if (check(mid) > 0) {
            r = mid;
        }else {
            l = mid;
        }
    }
    
    cout << fixed << setprecision(4) << (l + r) / 2 << '\n';
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