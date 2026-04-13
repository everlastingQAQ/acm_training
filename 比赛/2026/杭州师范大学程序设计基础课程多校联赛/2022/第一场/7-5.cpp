#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    char o;
    cin >> o;

    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    ll sum = ((a % 10) * (b % 10) * (c % 10) * (d % 10)) % 10;

    ll ans1 = e % 10;

    if (o != 'p') {
        cout << "meidechi,555 " << sum << endl;
        return;
    }

    if (ans1 == sum) {
        cout << "hihihi,yaquyuebing,hihihi " << sum << endl;
        return;
    }else {
        cout << "meidechi,555 " << sum << endl;
        return;
    }

    return;
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