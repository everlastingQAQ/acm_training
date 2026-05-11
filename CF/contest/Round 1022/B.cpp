#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n, x;

void solve ()
{
    cin >> n >> x;
    if (x == 0) {
        if (n == 1) {
            cout << -1 << '\n';
        }else {
            if (n & 1) {
                cout << 5 + n - 2 << '\n';
            }else {
                cout << n << '\n';
            }
        }
        return;
    }else if (x == 1) {
        if (n & 1) {
            cout << n << '\n';
        }else {
            cout << 5 + n - 2 << '\n';
        }
        return;
    }

    ll cnt = 0;
    for (int i = 0; i < 33; i++) {
        if ((x >> i) & 1) {
            cnt++;
        }
    }

    if (cnt >= n) {
        cout << x << '\n';
        return;
    }

    ll t = n - cnt;
    if (t & 1) {
        cout << x + 1 + t << '\n';
    }else {
        cout << x + t << '\n';
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
