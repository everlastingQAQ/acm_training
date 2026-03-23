#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, m, r1, r2, c1, c2;
  	cin >> n >> m >> r1 >> c1 >> r2 >> c2;
  	if (n == 1 || m == 1) {
  		if (m == 1) {
			swap(n, m);
			swap(r1, c1);
			swap(r2, c2);
		}
  		if ((n * m) & 1) {
  			cout << "NO\n";
  			return;
  		}
  		if (c1 > c2) swap(c1, c2);
  		if (((c1 - 1) & 1) || ((c2 - c1 + 1) & 1) || ((m - c2) & 1)) {
  			cout << "NO\n";
  		}else {
  			cout << "YES\n";
  		}
  		return;
  	}
  	if (((n * m) & 1) || !((abs(r1 - r2) + abs(c1 - c2)) & 1)) {
  		cout << "NO\n";
  	}else {
  		cout << "YES\n";
  	}  
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