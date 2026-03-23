#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

void solve ()
{
  	string s, t;
  	cin >> s >> t;
  	vector <int> cnt(10, 0);
  	for (auto c : s) {
  		cnt[c - '0']++;
  	}
  	for (auto c : t) {
  		cnt[c - '0']++;
  	}
  	int l = max(s.size(), t.size());
  	vector <int> wei(l, 0);
  	for (int i = 0; i < s.size(); i++) {
  		wei[i]++;
  	}
  	for (int i = 0; i < t.size(); i++) {
  		wei[i]++;
  	}

  	i64 ans = 0;
  	int cur = 9;
  	for (int i = l - 1; i >= 0; i--) {
  		ans = 10LL * ans % mod;
  		while (wei[i]--) {
  			while (!cnt[cur]) cur--;
  			ans = (ans + cur) % mod;
  			cnt[cur]--;
  		}
  	}

  	cout << ans;
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 