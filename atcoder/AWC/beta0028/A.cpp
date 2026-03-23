#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, k;
  	cin >> n >> k;
  	for (int i = 1; i <= n; i++) {
  		i64 t;
  		cin >> t;
  		if (i % k == 0) {
  			cout << t << ' ';
  		}
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