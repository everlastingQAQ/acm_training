#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, m;
  	cin >> n >> m;
  	vector <array <int, 2> > v(m + 1, {0, 0});
  	for (int i = 1; i <= n; i++) {
  		int a, b;
  		cin >> a >> b;
  		v[a][0]++;
  		v[b][1]++;
  	}  
  	for (int i = 1; i <= m; i++) {
  		cout << v[i][1] - v[i][0] << '\n';
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