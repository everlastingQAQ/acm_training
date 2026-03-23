#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, t;
  	i64 e;
  	cin >> n >> t >> e;
  	vector <i64> v(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  		v[i] *= t;
  	}  
  	sort(v.begin() + 1, v.end());
  	i64 sum = 0;
  	for (int i = 1; i <= n; i++) {
  		sum += v[i];
  		if (sum > e) {
  			cout << i - 1 << '\n';
  			return;
  		}
  	}
  	cout << n << '\n';
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