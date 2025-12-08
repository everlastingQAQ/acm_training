#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
//const double eps = 1e-5;

void solve ()
{
    long double eps;
    cin >> eps;

    long double sum = 0;

    long double t = 1;
    int i = 1;
    while (t > eps) {
        t = 1.0 / (i * (2 * i - 1));
        sum += 1.0 * t;
        i++;
    }

    cout << fixed << setprecision(6) << sum << endl;
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