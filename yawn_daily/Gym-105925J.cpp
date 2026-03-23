#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	i64 k;
  	cin >> n >> k;
  	vector <i64> v(2 * n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  	}  
  	for (int i = 1; i <= n; i++) {
  		v[i + n] = v[i];
  	}

  	for (int i = 1; i <= 2 * n; i++) {
  		v[i] -= i * k;
  	}

  	vector <int> stk;
  	vector <int> ans(n + 1);
  	for (int i = 2 * n; i >= 0; i--) {
  		while (!stk.empty() && v[stk.back()] >= v[i]) {
  			stk.pop_back();
  		}
  		if (i <= n) ans[i] = (stk.back() - 1) % n + 1;
  		stk.push_back(i);
  	}

  	for (int i = 1; i <= n; i++) {
  		cout << ans[i] << ' ';
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