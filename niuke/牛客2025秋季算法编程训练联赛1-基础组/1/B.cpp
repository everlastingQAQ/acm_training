#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100010;
int a[MAXN];
bool b[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    ll n, x, a, b;
    cin >> n >> x >> a >> b;

    double ans1 = 1.0 * a * x / 100;
    double ans2 = 1.0 * b * (100 - x) / 100;

    double ans = (ans1 + ans2) * n;

    cout << fixed << setprecision(2) << ans << endl;

    return;

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