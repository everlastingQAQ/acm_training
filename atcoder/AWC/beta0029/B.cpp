#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, q;
  	cin >> n >> q;
  	vector <i64> v(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  	}  
  	while (q--) {
  		int op;
  		cin >> op;
  		if (op == 1) {
  			int a, b;
  			cin >> a >> b;
  			v[b] += v[a];
  			v[a] = 0;
  		}else if (op == 2) {
  			int c;
  			cin >> c;
  			cout << v[c] << '\n';
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