#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	string s;
  	cin >> s;
  	int ans = 1;
  	int l = 0, r = 0;
  	while (r < s.size()) {
  		while (s[r] == s[l]) {
  			r++;
  		}
  		ans = max(ans, r - l);
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