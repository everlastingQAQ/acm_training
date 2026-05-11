#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n, k;

ll power (ll a, ll b)
{
    ll ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

bool check (ll x)
{
    ll sum = x;

    ll t = 1;
    ll i = 1;
    while (t != 0) {
        ll temp = power(k, i);
        t = x / temp;
        sum += t;
        i++;
    }

    if (sum >= n) {
        return true;
    }else {
        return false;
    }

}

void solve ()
{
    cin >> n >> k;

    ll l = 0, r = n;

    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        //cout << mid << endl;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
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