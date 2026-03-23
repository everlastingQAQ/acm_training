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
  	for (int i = 1; i <= n; i++) {
  		i64 c0 = 0, c1 = 0;
  		for (int j = i + 1; j <= n; j++) {
  			if (v[j] > v[i]) c0++;
  			else if (v[j] < v[i]) c1++;
  		}
  		cout << max(c0, c1) << ' ';
  	}
  	cout << '\n';
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