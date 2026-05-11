#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <int> a(n + 1), b(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  	}  
  	for (int i = 1; i <= n; i++) {
  		cin >> b[i];
  	}

  	int ans = 0;
  	for (int i = 1; i <= n; i++) {
  		if (i == 1 && a[i] != gcd(a[i], a[i + 1])) {
  			ans++;
  		}else if (i == n && a[i] != gcd(a[i], a[i - 1])) {
  			ans++;
  		}else {
  			int t1 = gcd(a[i], a[i - 1]);
  			int t2 = gcd(a[i], a[i + 1]);
  			int t = lcm(t1, t2);
  			if (t != a[i]) ans++;
  		}
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