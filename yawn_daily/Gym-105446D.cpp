#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	double p, r, y;
    cin >> p >> r >> y;
    double a = 0;
    double b = (y - p - r) / 2;
    double c = -p;
    double d = (y - p + r) / 2;
    double l = min({a, b, c, d});
    double rr = max({a, b, c, d});
    double w = (l + rr) / 2;
    double e = p + w;
    double s = b - w;
    double n = d - w;
    cout << fixed << setprecision(10);
    cout << n << ' ' << e << ' ' << s << ' ' << w << '\n';
} 

int main ()
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