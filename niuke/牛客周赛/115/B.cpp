#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n, m;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    ll n, k;
    cin >> n >> k;

    ll t;
    if (k == 0) {
        t = 1;
    }else {
        t = pow(2, k);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += t;
    }

    cout << ans << endl;
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