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
    vector <vector <ll> > v(n, vector <ll> (n));
    ll cnt = n * n - 1;
    for (int i = 0; i < n / 2; i++) {
        ll x = i;
        for (int j = i; j < n - i; j++) {
            v[i][j] = cnt--;
        }
        for (int j = i + 1; j < n - i; j++) {
            v[j][i] = cnt--;
        }
        for (int j = i + 1; j < n - i; j++) {
            v[j][n - i - 1] = cnt--;
        }
        for (int j = i + 1; j < n - i - 1; j++) {
            v[n - i - 1][j] = cnt--;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
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
