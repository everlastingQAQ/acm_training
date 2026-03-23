#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <i64> v(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  	}  
  	sort(v.begin() + 1, v.end());
  	i64 ans = 1e11;
  	for (int i = 2; i <= n; i++) {
  		ans = min(ans, (v[i] ^ v[i - 1]));
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