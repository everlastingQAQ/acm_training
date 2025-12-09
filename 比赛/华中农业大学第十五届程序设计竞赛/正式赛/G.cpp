#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());

    auto check = [&] (ll md) -> bool {
        ll l = 1;
        for (int i = 1; i <= n; i++) {
            if (v[i] - v[1] <= md) {
                l = i;
            }else {
                break;
            } 
        }
        ll r = n;
        for (int i = n - 1; i >= 1; i--) {
            if (v[n] - v[i] <= md) {
                r = i;
            }else {
                break;
            }
        }
        return r <= l + 1;
    };

    ll l = 0, r = v[n]; 
    while (l <= r) {
        ll mid = l + ((r - l) >> 1);
        if (check(mid)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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
