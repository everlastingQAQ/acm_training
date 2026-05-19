#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve ()
{
  	u64 n;
  	cin >> n;
  	for (u64 i = 1; i <= n; i++) {
  		u64 ans = i * i * (i * i - 1) / 2 - 2 * (i - 1) * (i - 2) * 2;
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