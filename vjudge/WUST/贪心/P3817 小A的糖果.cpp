#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n, x;

void solve ()
{
    cin >> n >> x;

    vector <ll> a;

    for (int i = 0; i < n; i++) {
        ll q;
        cin >> q;
        a.push_back(q);
    }

    ll sum = 0;
    if (a[0] > x) {
        sum += a[0] - x;
        a[0] = x;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            int t = a[i] + a[i + 1] - x;
            sum += t;
            a[i + 1] -= t;
        }
    }

    cout << sum << endl;
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