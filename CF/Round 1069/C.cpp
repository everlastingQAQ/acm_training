#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

string s, t;

void solve ()
{
    cin >> s >> t;
    map <char, ll> mp1;
    for (char c : s) {
        mp1[c]++;
    }
    map <char, ll> mp2;
    for (char c : t) {
        mp2[c]++;
    }
    for (auto [x, y] : mp1) {
        if (mp2[x] < y) {
            cout << "Impossible" << '\n';
            return;
        }
    }

    sort(t.begin(), t.end());
    ll pos = 0;
    string ans;
    for (char c = 'a'; c <= 'z'; c++) {
        if (mp2[c] == 0) continue;
        while (pos < s.size() && c >= s[pos]) {
            ans += s[pos];
            pos++;
        }
        for (int i = 0; i < mp2[c] - mp1[c]; i++) {
            ans += c;
        } 
    }
    cout << ans << '\n';
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
