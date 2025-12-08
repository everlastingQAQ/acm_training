#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ans1 = abs(x1 - x2) + abs(y1 - y2);
    int ans2 = max(abs(x1 - x2) , abs(y1 - y2));

    cout << ans1 << ' ' << ans2;
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