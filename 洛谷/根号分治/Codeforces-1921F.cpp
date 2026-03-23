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
  	int m = sqrt(n);
  	vector <vector <i64> > a(m + 1);
  	for (int i = 1; i <= m; i++) {
  		a[i].assign(i, 0);
  	}
  	for (int i = 1; i <= m; i++) {
  		for (int j = 1; j <= n; j++) {
  			a[i][j % i] += v[j];
  		}
  	}

  	while (q--) {
  		int s, d, k;
  		cin >> s >> d >> k;

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