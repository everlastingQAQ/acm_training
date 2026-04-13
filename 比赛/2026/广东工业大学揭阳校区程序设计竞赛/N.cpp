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
  	vector <int> a(n + 1);
  	int len = 1;
  	a[1] = v[1];
  	for (int i = 2; i <= n; i++) {
  		int pos = lower_bound(a.begin() + 1, a.end(), a[i]) - a.begin();
  		a[pos] = v[i];
  		if (pos > len) len++;
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