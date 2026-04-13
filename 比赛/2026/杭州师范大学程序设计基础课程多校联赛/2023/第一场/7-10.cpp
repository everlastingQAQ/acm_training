#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10000 + 5;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    int x, y, q, pos, t;
    cin >> x >> y >> q >> pos >> t;

    int sum = t * (pos - 1);

    int cnt = (sum - q) / y;

    int cnt_0 = sum / x;

    if (cnt > cnt_0) {
        cout << "Yes" << endl;
    }else if (cnt == cnt_0) {
        cout << "So So" << endl;
    }else {
        cout << "No" << endl;
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