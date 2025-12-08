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
string s;

void solve ()
{
	cin >> n >> s;
    ll cnt = 0;
    map <ll, ll> mp;
    for (char c : s) {
        if (mp[c - 'a'] == 0) {
            cnt++;
        }
        mp[c - 'a']++;
    }

    if (cnt < 3) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (i == j || i == k || j == k) continue;
                if (mp[k] == 0 || mp[j] == 0 || mp[i] == 0) continue;
                ans += mp[k] * mp[j] * mp[i]; 
                ans %= mod;
            }
        }
    }

    cout << ans << '\n';
}

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
