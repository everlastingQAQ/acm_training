#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
long double n, j, vj, h, vh;

void solve ()
{
    cin >> n >> j >> vj >> h >> vh;
    //cout << n << ' ' << j << ' ' << vj << ' ' << h << ' ' << vh << endl;
    
    long double t11 = (h - j) / (vj + vh);

    long double x1 = j + (h - j) / (vj + vh) * vj;
    long double x2 = n - x1;
    long double t12 = max(x1 / vj, x2 / vh);
    long double t1 = t11 + t12;
    //cout << t1 << endl;

    long double t2 = (n + j + n - h) / (vj + vh);

    long double t3 = (j + n) / vj;

    long double t4 = (n - h + n) / vh;

    long double t5 = (n + j) / vh;

    long double t6 = (n - h + n) / vj;

    //cout << t1 << ' ' << t2 << endl;
    
    cout << fixed << setprecision(5) << min({t1, t2, t3, t4, t5, t6}) << endl;

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