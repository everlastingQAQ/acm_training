#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
  	int n, k;
  	cin >> n >> k;
  	vector <int> v(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  	}  
  	sort(v.begin() + 1, v.end());
  	int l = 1, r = 1;
  	int ans = 1;
  	while (r <= n) {
  		while (r <= n && v[r] - v[l] <= 2 * k) {
  			r++;
  		}
  		ans = max(ans, r - l);
  		l++;
  	}
  	cout << ans << '\n';
} 

int32_t main ()
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