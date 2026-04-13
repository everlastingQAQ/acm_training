#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    ll x, y, z;
    cin >> x >> y >> z;
    ll a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    sort(a, a + 4, cmp);

    ll sum = a[0] + a[1] + a[2];

    ll k;
    cin >> k;

    sum *= k;

    if (sum > x) {
        cout << 'A' << endl;
        return;
    }else if (sum > y) {
        cout << 'B' << endl;
        return;
    }else if (sum > z) {
        cout << 'C' << endl;
        return;
    }else {
        cout << "POOR" << endl;
        return;
    }
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