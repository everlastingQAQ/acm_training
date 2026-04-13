#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    ll a, b;
    cin >> a >> b;

    if (a == 0) {
        cout << 1 << endl;
        return;
    }

    ll sum = a + b * 2;

    cout << sum + 1 << endl;

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