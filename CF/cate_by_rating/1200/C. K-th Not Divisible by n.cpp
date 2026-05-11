#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    int n, k;
    cin >> n >> k;

    if (n > k) {
        cout << k << endl;
        return;
    }else {
        int p = ceil(1.0 * k / (n - 1) - 1);
        cout << p + k << endl;
        return;
    }
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
