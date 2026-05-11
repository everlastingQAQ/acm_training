#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 n;
  	cin >> n;
  	vector <i64> x(n + 1), y(n + 1);
  	multiset <i64> a, b;
  	for (int i = 1; i <= n; i++) {
  		cin >> x[i] >> y[i];
  		a.insert(x[i]);
  		b.insert(y[i]);
  	}

  	i64 ans = (*a.rbegin() - *a.begin() + 1) * (*b.rbegin() - *b.begin() + 1);
  	for (int i = 1; i <= n; i++) {
  		a.erase(a.find(x[i]));
  		b.erase(b.find(y[i]));
  		if (a.empty() || b.empty()) continue;
  		i64 xx = *a.rbegin() - *a.begin() + 1;
  		i64 yy = *b.rbegin() - *b.begin() + 1;
  		i64 cur = xx * yy;
  		if (cur < n) {
  			ans = min({ans, cur + xx, cur + yy});
  		}else {	
  			ans = min(ans, cur);
  		}
  		a.insert(x[i]);
  		b.insert(y[i]);
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