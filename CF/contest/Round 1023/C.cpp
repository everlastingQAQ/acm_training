#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n, k;
string s;

void solve ()
{
    cin >> n >> k >> s;
    s = ' ' + s;
    vector <ll> v(n + 1);
    ll pos = -1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (s[i] == '0') {
            v[i] = -1e13;
            pos = i;
        }
    }
    ll mx = 0;
    ll curr = 0;
    for (int i = 1; i <= n; i++) {
        curr = max(curr + v[i], v[i]);
        mx = max(mx, curr);
    }
    if (mx > k || (mx != k && pos == -1)) {
        cout << "No" << '\n';
        return;
    }

    if (mx == k) {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    mx = 0, curr = 0;
    for (int i = pos + 1; i <= n; i++) {
        curr += v[i];
        mx = max(mx, curr);
    }
    ll a = mx;
    mx = 0, curr = 0;
    for (int i = pos - 1; i >= 1; i--) {
        curr += v[i];
        mx = max(mx, curr);
    }
    ll b = mx;
    v[pos] = k - a - b;
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
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
