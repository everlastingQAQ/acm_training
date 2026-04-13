#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int x, y;
  	cin >> x >> y;
  	if (x == y) {
  		cout << 1 << '\n';
  	}else {
  		int cnt = 0;
  		for (int i = 1; i * i <= abs(x - y); i++) {
  			if (abs(x - y) % i == 0) {
  				cnt += 2;
  				if (i * i == abs(x - y)) cnt--;
  			}
  		}
  		cout << cnt << '\n';
  	}
  		
  	for (int i = 1; i <= x; i++) {
  		cout << 1 << ' ';
  	}
  	for (int i = 1; i <= y; i++) {
  		cout << -1 << ' ';
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