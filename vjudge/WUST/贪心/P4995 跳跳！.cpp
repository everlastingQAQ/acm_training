#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), cmp);

    ll l = 0, r = n - 1;

    ll ans = 0;
    ans += a[0] * a[0];
    while (l <= r) {
        ans += (a[l] - a[r]) * (a[l] - a[r]);
        l++;
        if (l > r) {
            break;
        }
        ans += (a[l] - a[r]) * (a[l] - a[r]);
        r--;
    }

    cout << ans << endl;
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