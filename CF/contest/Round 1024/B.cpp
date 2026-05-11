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
        v[i] = abs(v[i]);
    }
    ll t = v[1];
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) {
        if (v[i] == t) {
            if (i <= n / 2 + 1) {
                cout << "Yes" << '\n';
            }else {
                cout << "No" << '\n';
            }
        }
    }

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
