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
    vector <ll> v(n);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == mx) {
            cnt++;
        }
    }
    if (cnt == n) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        if (v[i] != mx) {
            cout << 1 << ' ';
        }else {
            cout << 2 << ' ';
        }
    }
    cout << '\n';
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
