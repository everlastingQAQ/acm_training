#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-3;
double a3, a2, a1, a0;
double ll, rr;

double check (double x)
{
    double ans = 1.0 * a3 * x * x * x + a2 * x * x + a1 * x + a0;
    return ans;
}

void solve ()
{
    cin >> a3 >> a2 >> a1 >> a0;

    double l, r;
    cin >> l >> r;

    double ans;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (fabs(check(mid)) < eps) {
            cout << fixed << setprecision(2) << mid;
            return;
        }
        if (check(l) * check(mid) < 0) {
            r = mid;
        }else if (check(r) * check(mid) < 0) {
            l = mid;
        }
    }
    
    cout << fixed << setprecision(2) << (r + l) / 2;
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