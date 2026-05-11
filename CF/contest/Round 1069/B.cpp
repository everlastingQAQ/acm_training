#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n, l, r;

void solve ()
{
    cin >> n >> l >> r;
    vector <ll> a(n + 1);
    vector <ll> ans(n + 1);
    
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }

    a[r] = a[l - 1];

    for (int i = 1; i <= n; i++) {
        cout << (a[i] ^ a[i - 1]) << ' ';
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
