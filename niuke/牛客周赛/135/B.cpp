#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <int> v(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  	} 

  	vector <int> a(n + 1);
  	for (int i = 1; i <= n; i++) {
  		a[i] = v[i] - i;
  	}
  	map <int, int> mp;
  	int ans = 1;
  	for (int i = 1; i <= n; i++) {
  		mp[a[i]]++;
  		ans = max(ans, mp[a[i]]);
  	}
  	cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 