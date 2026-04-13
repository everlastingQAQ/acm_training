#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <int> v(n + 1);
  	map <int, int> mp;
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  		mp[v[i]]++;
  	}  
  	if (mp[v[1]] == n) {
  		cout << -1 << '\n';
  		return;
  	}

  	sort(v.begin() + 1, v.end());
  	int pos = (n + 1) / 2;
  	int l = pos;
  	while (l >= 2 && v[l - 1] == v[pos]) {
  		l--;
  	}
  	int r = pos;
  	while (r <= n - 1 && v[r + 1] == v[pos]) {
  		r++;
  	}
  	int ans = min(n - 2 * (l - 1), n - (2 * (n - r) - 1));
  	cout << ans << '\n';
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