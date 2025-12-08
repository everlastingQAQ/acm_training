#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
vector <ll> a;
ll n, m;

bool check (ll x)
{
    ll sum = 0;
    for (ll p : a) {
        sum += max(1LL * 0, p - x);
    }

    if (sum >= m) {
        return true;
    }else {
        return false;
    }
}

void solve ()
{
    cin >> n >> m;

    a.clear();
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll a1;
        cin >> a1;
        mx = max(a1, mx);
        a.push_back(a1);
    }

    ll l = 0, r = mx;

    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }else {
            r = mid - 1;
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
