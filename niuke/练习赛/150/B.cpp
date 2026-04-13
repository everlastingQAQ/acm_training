#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	i64 ans = 1;
  	bool ok = false;
  	int cnt = 0;
  	for (int i = 1; i <= n; i++) {
  		i64 l, r;
  		cin >> l >> r;
  		if (ok) continue;
  		if (l != r) {
  			ok = true;
  			continue;
  		}
  		if (cnt == 0) {
  			ans = l;
  			cnt = 1;
  		}else {
  			ans = gcd(ans, l);
  		}
  	}  
  	if (ok) {
  		cout << 1 << '\n';
  	}else {
  		cout << ans << '\n';
  	}
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