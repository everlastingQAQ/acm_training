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

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll mx = *max_element(v.begin(), v.end());
    ll mn = *min_element(v.begin(), v.end());
    ll cntmx = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == mx) {
            cntmx++;
        }
    }

    if (mx - mn > k + 1 || (mx - mn == k + 1 && cntmx != 1)) {
        cout << "Jerry" << '\n';    
        return; 
    }   

    if (sum & 1) {
        cout << "Tom" << '\n';
    }else {
        cout << "Jerry" << '\n';
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
