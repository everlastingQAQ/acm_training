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
    vector<ll> v;
    map <ll, bool> mp;

    v.push_back(-1e9);
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if (v.back() != t) {
            v.push_back(t);
        }
    }
    v.push_back(-1e9);

    ll cnt = 0;

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            cnt++;
        }
    }

    cout << cnt << '\n';
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
