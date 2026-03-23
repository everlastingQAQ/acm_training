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
  	int l = 1, r = 1;
  	int ans = 1;
  	while (r <= n) {
  		while (abs(v[r] - v[r - 1]) <= 1) {
  			r++;
  		}
  		ans = max(ans, r - l + 1);
  		r++;
  		l = r;
  	}
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