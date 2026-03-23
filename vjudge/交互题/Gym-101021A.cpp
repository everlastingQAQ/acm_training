#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int l = 1, r = (int)1e6;
  	int ans = 0;
  	while (l <= r) {
  		int mid = l + (r - l) / 2;
  		cout << mid << endl;
  		string s;
  		cin >> s;
  		if (s == ">=") {
  			ans = mid; l = mid + 1;
  		}else {
  			r = mid - 1;
  		}
  	}
  	cout << "! " << ans << '\n';
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