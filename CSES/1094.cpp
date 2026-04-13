#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <i64> v(n + 1);
  	i64 ans = 0;
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  		if (i > 1) ans += max(0LL, v[i - 1] - v[i]);
  		v[i] = max(v[i], v[i - 1]);
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