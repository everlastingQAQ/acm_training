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
    set <ll> st;
    ll mx = 0;
    ll mn = 1e9;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        st.insert(t);
    }

    ll cnt = st.size();
    bool found = false;

    for (auto it = st.begin(); it != st.end(); it++) {
        if (*it >= cnt) {
            found = true;
            cout << *it << '\n';
            return;
        }
    }

    if (!found) {
        cout << *max_element(st.begin(), st.end()) << '\n';
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
