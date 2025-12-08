#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const double eps = 1e-5;
double a, b, c, d;

double check (double x)
{
    return (a * x * x * x + b * x * x + c * x + d); 
}

int cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> a >> b >> c >> d;

    for (int i = -100; i < 100; i++) {
        double l = i, r = i + 1;
        double mid;
        if (fabs(check(l)) < eps) {
            cout << fixed << setprecision(2) << l << ' ';
        }else if (fabs(check(r)) < eps) {
            continue;
        }else if (check(l) * check(r) < 0) {
            while (r - l > eps) {
                mid = l + (r - l) / 2;
                if (check(mid) * check(r) > 0) {
                    r = mid;
                }else {
                    l = mid;
                }
            }
            cout << fixed << setprecision(2) << l << ' ';
        }
    }
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}